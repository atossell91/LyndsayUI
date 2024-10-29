#include "../include/RixinSDL.h"

#include <thread>
#include <chrono>
#include <list>
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "../include/RixinSDLContext.h"
#include "../include/interfaces/IUpdateable.h"
#include "SDLEventManager.h"

RixinSDL::RixinSDL::RixinSDL() {
    eventManager = std::make_unique<SDLEventManager>();

    initSDL();
    initOpenGl();
    init();
}

void RixinSDL::RixinSDL::initSDL() {
    if (!SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO)) {
        std::cout << "SDL Init failed." << std::endl;
    }

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
}

void RixinSDL::RixinSDL::initOpenGl() {
    // Nothing to be done here (at the moment)
}

void RixinSDL::RixinSDL::init() {
    // Empty function, maybe delete?
}

void RixinSDL::RixinSDL::mainLoop() {
    while (!gameContext.ShouldClose) {
        eventManager->ProcessEvents();
        std::this_thread::sleep_for(
            std::chrono::milliseconds(kMainLoopDelay));
    }
}

void RixinSDL::RixinSDL::Run() {
    mainLoop();
    cleanup();
}

void RixinSDL::RixinSDL::cleanup() {
    SDL_Quit();
}
