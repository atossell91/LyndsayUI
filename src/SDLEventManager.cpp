#include "SDLEventManager.h"

#include <SDL3/SDL.h>
#include <functional>

#include <iostream>

using namespace RixinSDL;

//  Declare functions here
void RixinSDL::SDLEventManager::ProcessEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        HandleEvent(event);
    }
}

void SDLEventManager::HandleEvent(SDL_Event& event) {
    std::cout << "Event type " << event.type << std::endl;
    switch (event.type)
    {
    case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
        for (auto handler : closeWindowHandlers) {
            handler(event.window.windowID);
        }
        break;
    case SDL_EVENT_KEY_DOWN:
        for (auto handler : keyDownHandlers) {
            handler(event.key.key);
        }
        break;

    case SDL_EVENT_KEY_UP:
        for (auto handler : keyUpHandlers) {
            handler(event.key.key);
        }
        break;

    case SDL_EVENT_MOUSE_MOTION:
        for (auto handler : this->mouseMoveHandlers) {
            SDL_MouseMotionEvent ev = *(reinterpret_cast<SDL_MouseMotionEvent*>(&event));
            handler(ev.x, ev.y);
        }
        break;

    case SDL_EVENT_MOUSE_BUTTON_DOWN:
        for (auto handler : this->mouseButtonDownHandlers) {
            //handler();
        }
        break;

    case SDL_EVENT_MOUSE_BUTTON_UP:
        for (auto handler : this->mouseButtonUpHandlers) {
            //handler();
        }
        break;

    case SDL_EVENT_QUIT:
        for (auto handler : this->quitHandlers) {
            handler();
        }
        break;
    
    default:
        break;
    }
}

void SDLEventManager::AddQuitHandler(std::function<void()> handler) {
    this->quitHandlers.push_back(handler);
}

void SDLEventManager::AddKeyDownHandler(std::function<void(int)> handler) {
    keyDownHandlers.push_back(handler);
}

void SDLEventManager::AddKeyUpHandler(std::function<void(int)> handler) {
    keyUpHandlers.push_back(handler);
}

void SDLEventManager::AddMouseButtonDownHandler(std::function<void(int)> handler) {
    mouseButtonDownHandlers.push_back(handler);
}

void SDLEventManager::AddMouseButtonUpHandler(std::function<void(int)> handler) {
    mouseButtonUpHandlers.push_back(handler);
}

void SDLEventManager::AddMouseMoveHandler(std::function<void(float posX, float posY)> handler) {
    mouseMoveHandlers.push_back(handler);
}

void SDLEventManager::AddCloseWindowHandler(std::function<void(int id)> handler) {
    closeWindowHandlers.push_back(handler);
}
