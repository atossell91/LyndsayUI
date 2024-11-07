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
#include "Event/IEventRouter.h"
#include "Event/EventRouter.h"
#include "Event/EventSpace.h"

#include "MappedIndexResolver.h"

RebeccaUI::RebeccaUI::RebeccaUI() {
    initSDL();
    initOpenGl();
    init();
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

    //  The WindowManager class needs to be modified to update the resolver
    //    when a new window is created
    //  Need to cast the windowResolver, or something
    windowManager = std::make_unique<WindowManager>(resolver);
    eventFactory = std::make_shared<EventFactory>();
    eventRouter = std::make_shared<EventRouter>(resolver);

    // Might want to give this a 'copy' of the IndexResolver -- It makes more sense for this
    //  to resolve the window ID from the SDL window, no?
    eventManager = std::make_unique<SDLEventManager>(eventFactory, eventRouter, resolver);
}

void RebeccaUI::RebeccaUI::registerEvents() {
    eventFactory->registerEvent(EventTypes::CLOSE_BUTTON_PRESSED_EVENT, [](){ return std::make_unique<CloseButtonPressedEvent>();});
}

void RebeccaUI::RebeccaUI::mainLoop() {
    while (!gameContext.ShouldClose) {
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
