#include "../include/RebeccaUI.h"

#include <thread>
#include <chrono>
#include <list>
#include <iostream>
#include <memory>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "RebeccaUIContext.h"
#include "IUpdateable.h"

#include "Event/EventTypes.h"
#include "Event/SDLEventManager.h"
#include "Event/EventSpace.h"
#include "Event/EventTent.h"

#include "MappedIndexResolver.h"

#include "Window/SDLWindowFactory.h"
#include "Window/IWindowFactory.h"
#include "Window/WindowFactory.h"

RebeccaUI::RebeccaUI::RebeccaUI() {
    initSDL();
    initOpenGl();
    init();
    registerEvents();
}

void RebeccaUI::RebeccaUI::initSDL() {
    if (!SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO)) {
        std::cout << "SDL Init failed." << std::endl;
    }

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
}

void RebeccaUI::RebeccaUI::initOpenGl() {
    // Nothing to be done here (at the moment)
}

void RebeccaUI::RebeccaUI::init() {
    std::shared_ptr<MappedIndexResolver> resolver = std::make_shared<MappedIndexResolver>();
    windowResolver = resolver;

    eventTent = std::make_unique<EventTent>();

    //  The WindowManager class needs to be modified to update the resolver
    //    when a new window is created
    //  Need to cast the windowResolver, or something

    auto winMgrEventTent = std::make_unique<EventTent>();

    auto sdlWinFactory = std::make_unique<SDLWindowFactory>();
    auto winFactory = std::make_unique<WindowFactory>(std::move(sdlWinFactory), resolver);
    windowManager = std::make_unique<WindowManager>(std::move(winFactory), resolver, std::move(winMgrEventTent));
    eventFactory = std::make_shared<EventFactory>();
    
    eventManager = std::make_unique<SDLEventManager>(eventFactory, windowResolver, eventTent.get());

    // Might want to give this a 'copy' of the IndexResolver -- It makes more sense for this
    //  to resolve the window ID from the SDL window, no?
}

void RebeccaUI::RebeccaUI::registerEvents() {
    eventFactory->registerEvent(EventTypes::CLOSE_BUTTON_PRESSED_EVENT, [](){ return std::make_unique<CloseButtonPressedEvent>();});

    eventTent->AddEventResponse(EventTypes::CLOSE_BUTTON_PRESSED_EVENT, [this](std::unique_ptr<IEvent> event){
        // Send to the window manager
            std::cout << "SDL Close event (RebeccaUI Event Tent handler)" << std::endl;
        IEventReceiver* winReceiver = windowManager->GetEventReceiver();
        
        if(winReceiver) {
            winReceiver->RecieveEvent(std::move(event));
        }
    });
}

void RebeccaUI::RebeccaUI::mainLoop() {
    while (!gameContext.ShouldClose) {
        if (windowManager->IsNoWindows()) {
            break;
        }

        eventManager->ProcessEvents();
        std::this_thread::sleep_for(
            std::chrono::milliseconds(kMainLoopDelay));
    }
}

void RebeccaUI::RebeccaUI::Run() {
    mainLoop();
    cleanup();
}

void RebeccaUI::RebeccaUI::cleanup() {
    SDL_Quit();
}
