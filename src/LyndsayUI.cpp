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
#include "Event/LyndsayEventManager.h"

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
    std::shared_ptr<MappedIndexResolver> resolver = std::make_shared<MappedIndexResolver>();
    windowResolver = resolver;

    std::unique_ptr<IQueuedEventGetter> eventGetter = std::make_unique<SDLQueuedEventGetter>();
    std::unique_ptr<IEventTent> eventTent = std::make_unique<EventTent>();
    eventManager = std::make_unique<LyndsayEventManager>(
        std::move(eventGetter),
        std::move(eventTent)
    );

    //  The WindowManager class needs to be modified to update the resolver
    //    when a new window is created
    //  Need to cast the windowResolver, or something

    auto winMgrEventTent = std::make_unique<EventTent>();

    auto sdlWinFactory = std::make_unique<SDLWindowFactory>();
    auto winFactory = std::make_unique<WindowFactory>(std::move(sdlWinFactory), resolver);
    windowManager = std::make_unique<WindowManager>(std::move(winFactory), resolver, std::move(winMgrEventTent));
    eventFactory = std::make_shared<EventFactory>();

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
