#include "../include/RixinSDL.h"

#include <thread>
#include <chrono>
#include <list>
#include <iostream>

#include "../include/RixinSDLContext.h"
#include "../include/interfaces/IDrawable.h"
#include "../include/interfaces/IUpdateable.h"

RixinSDL::RixinSDL() {
    init();
}

void RixinSDL::init() {
    SDL_Init(kInitFlags);

    window = SDL_CreateWindow(gameName, kWindowWidth, kWindowHeight, 0);
    //renderer = SDL_CreateRenderer(window, NULL, 0);
    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        std::cout << "Renderer is null: " << SDL_GetError() << std::endl;
    }
}

void RixinSDL::mainLoop() {
    while (!gameContext.ShouldClose) {
        processEvents();
        draw();
        std::this_thread::sleep_for(
            std::chrono::milliseconds(kMainLoopDelay));
    }
}

void RixinSDL::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        eventDispatcher.HandleEvent(event);
    }
}

void RixinSDL::update() {
    for (auto updateable : updateables) {
        updateable->Update();
    }
}

void RixinSDL::draw() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (auto drawable : drawables) {
        drawable->Draw(renderer);
    }

    SDL_RenderPresent(renderer);
}

void RixinSDL::Run() {
    mainLoop();
    cleanup();
}

void RixinSDL::AddDrawable(IDrawable* drawable) {
    drawables.push_back(drawable);
}

void RixinSDL::RemoveDrawable(IDrawable* drawable) {
    drawables.remove(drawable);
}

void RixinSDL::AddUpdateable(IUpdateable* updateable) {
    updateables.push_back(updateable);
}

void RixinSDL::RemoveUpdateable(IUpdateable* updateable) {
    updateables.remove(updateable);
}

RixinSDLContext& RixinSDL::GetRixinSDLContext() {
    return this->gameContext;
}

EventDispatcher& RixinSDL::GetEventDispatcher() {
    return this->eventDispatcher;
}

void RixinSDL::cleanup() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
