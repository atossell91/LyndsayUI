#pragma once

#include <functional>
#include <list>
#include <SDL3/SDL.h>

class Iterable {
};

class EventDispatcher {
 private:
    std::list<std::function<void(SDL_Keycode)>> keyDownHandlers;
    std::list<std::function<void(SDL_Keycode)>> keyUpHandlers;
    std::list<std::function<void()>> quitHandlers;

 public:
    void AddKeyDownHandler(std::function<void(SDL_Keycode)> handler);
    void AddKeyUpHandler(std::function<void(SDL_Keycode)> handler);
    void AddQuitHandler(std::function<void()> handler);
    void HandleEvent(SDL_Event&);
};
