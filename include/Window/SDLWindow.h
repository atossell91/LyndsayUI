#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <iostream>

#include "Window/IWindow.h"
#include "Window/SDLWindowFactory.h"

namespace NSLyndsayUI {
    class SDLWindow : public IWindow {
    private:
        //  Private stuff here
        SDL_Window* window;
        SDL_GLContext glContext;
        SDLWindow(SDL_Window* win, SDL_GLContext glCon) : window{win}, glContext{glCon} {}
    public:
        //  Public stuff here
        ~SDLWindow() { SDL_DestroyWindow(window); }
        int GetWindowId() { return SDL_GetWindowID(window); }

        friend std::unique_ptr<IWindow> SDLWindowFactory::CreateWindow();

        // This is here because of IWindow, but it should be refactored out I think
        void Close () {}
    };
} // LyndsayUI
