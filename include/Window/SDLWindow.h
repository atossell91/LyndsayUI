#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <iostream>

#include "Drawing/GlGraphics.h"
#include "Window/IWindow.h"
#include "Window/SDLWindowFactory.h"

namespace NSLyndsayUI {
    class SDLWindow : public IWindow {
    private:
        //  Private stuff here
        SDL_Window* window;
        SDL_GLContext glContext;
        std::unique_ptr<IGraphics> graphics;
        SDLWindow(SDL_Window* win) : 
            window{win} {
                glContext = SDL_GL_CreateContext(window);
                graphics = std::make_unique<GlGraphics>(window, glContext);
            }
    public:
        //  Public stuff here
        ~SDLWindow() { SDL_DestroyWindow(window); }
        int GetWindowId() { return SDL_GetWindowID(window); }

        friend std::unique_ptr<IWindow> SDLWindowFactory::CreateWindow();

        // This is here because of IWindow, but it should be refactored out I think
        void Close () {}
        IGraphics* GetGraphics() { return graphics.get(); }
    };
} // LyndsayUI
