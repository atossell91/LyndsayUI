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

#include "Event/SDLEventManager.h"
#include "Event/ThreadEventManager.h"
#include "Event/WindowEventCoordinator.h"
#include "Event/IEventProcessor.h"

#include "MappedIndexResolver.h"

#include "Window/SDLWindowFactory.h"
#include "Window/IWindowFactory.h"
#include "Window/WindowFactory.h"

NSLyndsayUI::LyndsayUI::LyndsayUI() {
    initSDL();
    init();
}

void NSLyndsayUI::LyndsayUI::initSDL() {
    if (!SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO)) {
        std::cout << "SDL Init failed." << std::endl;
    }

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
}

void NSLyndsayUI::LyndsayUI::init() {
}

void NSLyndsayUI::LyndsayUI::mainLoop() {
    while (!gameContext.ShouldClose) {

        //// Process events
        eventManager->ProcessEvents();

        std::this_thread::sleep_for(
            std::chrono::milliseconds(kMainLoopDelay));
    }
}

void NSLyndsayUI::LyndsayUI::Run() {
    mainLoop();
    cleanup();
}

void NSLyndsayUI::LyndsayUI::cleanup() {
    SDL_Quit();
}
