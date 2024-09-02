#include "../include/RixinSDL.h"

#include <thread>
#include <chrono>
#include <list>
#include <iostream>
#include <SDL3_image/SDL_image.h>

#include "../include/RixinSDLContext.h"
#include "../include/interfaces/IUpdateable.h"

RixinSDL::RixinSDL::RixinSDL() {
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
    windowManager.AddWindow(defaultWindowTitle, 1920, 1080);

    auto& con = gameContext;
    auto& wMan = windowManager;
    eventDispatcher.AddCloseWindowHandler([this](int id){
        windowManager.CloseWindow(id);

        if (windowManager.GetNumWindows() < 1) {
            gameContext.ShouldClose = true;
        }
    });
}

void RixinSDL::RixinSDL::mainLoop() {
    while (!gameContext.ShouldClose) {
        processEvents();
        std::this_thread::sleep_for(
            std::chrono::milliseconds(kMainLoopDelay));
    }
}

void RixinSDL::RixinSDL::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        eventDispatcher.HandleEvent(event);
    }
}

void RixinSDL::RixinSDL::Run() {
    mainLoop();
    cleanup();
}

void RixinSDL::RixinSDL::cleanup() {
    SDL_Quit();
}
