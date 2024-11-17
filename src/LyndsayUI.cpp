#include "../include/LyndsayUI.h"

#include <thread>
#include <chrono>
#include <list>
#include <iostream>
#include <memory>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "LyndsayUIContext.h"
#include "IUpdateable.h"

#include "Event/EventTypes.h"
#include "Event/SDLEventManager.h"
#include "Event/EventSpace.h"
#include "Event/EventTent.h"
#include "Event/IQueuedEventGetter.h"
#include "Event/SDLQueuedEventGetter.h"
#include "Event/ThreadEventManager.h"
#include "Event/ExecutiveEventManager.h"

#include "MappedIndexResolver.h"

#include "Window/SDLWindowFactory.h"
#include "Window/IWindowFactory.h"
#include "Window/WindowFactory.h"

LyndsayUI::LyndsayUI::LyndsayUI() {
    initSDL();
    initOpenGl();
    init();
    registerEvents();
}

void LyndsayUI::LyndsayUI::initSDL() {
    if (!SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO)) {
        std::cout << "SDL Init failed." << std::endl;
    }

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
}

void LyndsayUI::LyndsayUI::initOpenGl() {
    // Nothing to be done here (at the moment)
}

void LyndsayUI::LyndsayUI::init() {

    //  Build the SDL Event Manager
    auto eventFactory = std::make_shared<EventFactory>();
    std::shared_ptr<IEventTent> eventTent = std::make_unique<EventTent>();
    std::unique_ptr<IEventManager> sdlMgr = std::make_unique<SDLEventManager>(eventFactory, eventTent);

    //  Build the Lyndsay Event Manager (for inter-thread communication)
    //    This is using an SDLQueuedEventGetter, but it shouldn't be
    std::unique_ptr<IQueuedEventGetter> eventGetter = std::make_unique<SDLQueuedEventGetter>();
    auto lyndsayMgr = std::make_unique<ThreadEventManager>(
        std::move(eventGetter),
        eventTent
    );

    //  Add both of the previous event managers to the excective event manager
    std::unique_ptr<ExecutiveEventManager> execMgr = std::make_unique<ExecutiveEventManager>();
    execMgr->AddManager(std::move(sdlMgr));
    execMgr->AddManager(std::move(lyndsayMgr));
    eventManager = std::move(execMgr);

    //  Build the window manager and it's dependencies
    //    The WindowManager class needs to be modified to update the resolver
    //      when a new window is created
    //    Need to cast the windowResolver, or something
    auto winMgrEventTent = std::make_unique<EventTent>();
    auto sdlWinFactory = std::make_unique<SDLWindowFactory>();
    std::shared_ptr<MappedIndexResolver> resolver = std::make_shared<MappedIndexResolver>();
    auto winFactory = std::make_unique<WindowFactory>(std::move(sdlWinFactory), resolver);
    windowManager = std::make_unique<WindowManager>(std::move(winFactory), resolver, std::move(winMgrEventTent));

    // Might want to give this a 'copy' of the IndexResolver -- It makes more sense for this
    //  to resolve the window ID from the SDL window, no?
}

void LyndsayUI::LyndsayUI::registerEvents() {
    /*
    eventFactory->registerEvent(EventTypes::CLOSE_BUTTON_PRESSED_EVENT, [](){ return std::make_unique<CloseButtonPressedEvent>();});

    eventTent->AddEventResponse(EventTypes::CLOSE_BUTTON_PRESSED_EVENT, [this](std::unique_ptr<IEvent> event){
        // Send to the window manager
            std::cout << "SDL Close event (LyndsayUI Event Tent handler)" << std::endl;
        IEventReceiver* winReceiver = windowManager->GetEventReceiver();
        
        if(winReceiver) {
            winReceiver->RecieveEvent(std::move(event));
        }
    });
    */
}

void LyndsayUI::LyndsayUI::mainLoop() {
    while (!gameContext.ShouldClose) {
        if (windowManager->IsNoWindows()) {
            break;
        }

        //// Process events
        eventManager->ProcessEvents();

        std::this_thread::sleep_for(
            std::chrono::milliseconds(kMainLoopDelay));
    }
}

void LyndsayUI::LyndsayUI::Run() {
    mainLoop();
    cleanup();
}

void LyndsayUI::LyndsayUI::cleanup() {
    SDL_Quit();
}
