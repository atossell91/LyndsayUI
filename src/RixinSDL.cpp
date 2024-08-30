#include "../include/RixinSDL.h"

#include <thread>
#include <chrono>
#include <list>
#include <iostream>
#include <SDL3_image/SDL_image.h>

#include "../include/RixinSDLContext.h"
#include "../include/interfaces/IUpdateable.h"

RixinSDL::RixinSDL::RixinSDL() {
    if (SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Init failed." << std::endl;
    }
    init();
}

void RixinSDL::RixinSDL::init() {
    std::cout << "Adding a window" << std::endl;
    windowManager.AddWindow(defaultWindowTitle, 1920, 1080);

    std::cout << "Adding an event" << std::endl;
    auto& con = gameContext;
    auto& wMan = windowManager;
    eventDispatcher.AddCloseWindowHandler([&con, &wMan](int id){
        wMan.CloseWindow(id);

        if (wMan.GetNumWindows() < 1) {
            con.ShouldClose = true;
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

void RixinSDL::RixinSDL::update() {
    for (auto updateable : updateables) {
        updateable->Update();
    }
}

void RixinSDL::RixinSDL::Run() {
    mainLoop();
    cleanup();
}

void RixinSDL::RixinSDL::AddUpdateable(IUpdateable* updateable) {
    updateables.push_back(updateable);
}

void RixinSDL::RixinSDL::RemoveUpdateable(IUpdateable* updateable) {
    updateables.remove(updateable);
}

void RixinSDL::RixinSDL::cleanup() {
    SDL_Quit();
}
