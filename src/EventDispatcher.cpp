#include "../include/EventDispatcher.h"

#include <functional>
#include <SDL3/SDL.h>

#include <iostream>

void EventDispatcher::HandleEvent(SDL_Event& event) {
    std::cout << "This address (handle): " << this << std::endl;
    std::cout << "List address: " << &quitHandlers << std::endl;

    if (event.type == SDL_EVENT_KEY_DOWN) {
        for (auto handler : keyDownHandlers) {
            //handler(event.key.keysym.sym);
            handler(event.key.key);
        }
    }
    else if (event.type == SDL_EVENT_QUIT) {
        std::cout << "Quitting" << std::endl;
        for (auto handler : this->quitHandlers) {
            handler();
        }
    }
}

void EventDispatcher::AddQuitHandler(std::function<void()> handler) {
    std::cout << "This address (add): " << this << std::endl;
    std::cout << "List address: " << &quitHandlers << std::endl;
    int a = 3;
    this->quitHandlers.push_back(handler);
    quitHandlers.front()();
}

void EventDispatcher::AddKeyDownHandler(std::function<void(SDL_Keycode)> handler) {
    keyDownHandlers.push_back(handler);
}

void EventDispatcher::AddKeyUpHandler(std::function<void(SDL_Keycode)> handler) {
    keyDownHandlers.push_back(handler);
}

