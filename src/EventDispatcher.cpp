#include "../include/EventDispatcher.h"

#include <functional>
#include <SDL3/SDL.h>

#include <iostream>

void EventDispatcher::HandleEvent(SDL_Event& event) {

    switch (event.type)
    {
    case SDL_EVENT_KEY_DOWN:
        for (auto handler : keyDownHandlers) {
            //handler(event.key.keysym.sym);
            handler(event.key.key);
        }
        break;

    case SDL_EVENT_KEY_UP:
        for (auto handler : keyUpHandlers) {
            //handler(event.key.keysym.sym);
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

void EventDispatcher::AddQuitHandler(std::function<void()> handler) {
    this->quitHandlers.push_back(handler);
}

void EventDispatcher::AddKeyDownHandler(std::function<void(SDL_Keycode)> handler) {
    keyDownHandlers.push_back(handler);
}

void EventDispatcher::AddKeyUpHandler(std::function<void(SDL_Keycode)> handler) {
    keyUpHandlers.push_back(handler);
}

void EventDispatcher::AddMouseButtonDownHandler(std::function<void(SDL_MouseButtonFlags)> handler) {
    mouseButtonDownHandlers.push_back(handler);
}

void EventDispatcher::AddMouseButtonUpHandler(std::function<void(SDL_MouseButtonFlags)> handler) {
    mouseButtonUpHandlers.push_back(handler);
}

void EventDispatcher::AddMouseMoveHandler(std::function<void(float posX, float posY)> handler) {
    mouseMoveHandlers.push_back(handler);
}
