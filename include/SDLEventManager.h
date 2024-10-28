#pragma once

#include <SDL3/SDL.h>

#include <list>
#include <functional>

#include "IEventManager.h"

namespace RixinSDL {
    class SDLEventManager : public IEventManager {
    private:
        //  Private stuff here
        std::list<std::function<void(SDL_Keycode)>> keyDownHandlers;
        std::list<std::function<void(SDL_Keycode)>> keyUpHandlers;
        std::list<std::function<void(SDL_MouseButtonFlags)>> mouseButtonDownHandlers;
        std::list<std::function<void(SDL_MouseButtonFlags)>> mouseButtonUpHandlers;
        std::list<std::function<void(float posX, float posY)>> mouseMoveHandlers;
        std::list<std::function<void()>> quitHandlers;
        std::list<std::function<void(int)>> closeWindowHandlers;
    public:
        //  Public stuff here
        void ProcessEvents();

        //  Assume SDL_KeyCode (for the up and down handlers)
        void AddKeyDownHandler(std::function<void(int)> handler);
        void AddKeyUpHandler(std::function<void(int)> handler);

        //  Assume SDL_MouseButtonFlags (for the up and down handlers)
        void AddMouseButtonDownHandler(std::function<void(int)> handler);
        void AddMouseButtonUpHandler(std::function<void(int)> handler);
        void AddMouseMoveHandler(std::function<void(float posX, float posY)> handler);
        void AddQuitHandler(std::function<void()> handler);

        void AddCloseWindowHandler(std::function<void(int)>handler);
        void HandleEvent(SDL_Event&);
    };
} // RixinSDL
