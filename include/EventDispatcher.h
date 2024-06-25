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
    std::list<std::function<void(SDL_MouseButtonFlags)>> mouseButtonDownHandlers;
    std::list<std::function<void(SDL_MouseButtonFlags)>> mouseButtonUpHandlers;
    std::list<std::function<void()>> quitHandlers;

 public:
    void AddKeyDownHandler(std::function<void(SDL_Keycode)> handler);
    void AddKeyUpHandler(std::function<void(SDL_Keycode)> handler);
    void AddMouseButtonDownHandler(std::function<void(SDL_MouseButtonFlags)> handler);
    void AddMouseButtonUpHandler(std::function<void(SDL_MouseButtonFlags)> handler);
    void AddMouseMoveUpHandler(std::function<void(SDL_MouseMotionEvent)> handler);
    void AddQuitHandler(std::function<void()> handler);
    void HandleEvent(SDL_Event&);
};
