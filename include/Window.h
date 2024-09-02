#pragma once

#include <string>
#include <thread>

#include <SDL3/SDL.h>

#include "glad/glad.h"
#include "../include/WindowDrawManager.h"

namespace RixinSDL
{
    class Window
    {
    private:
        int width;
        int height;

        bool windowRunning = true;

        SDL_Window* window;
        SDL_GLContext glContext;

        WindowDrawManager drawManager;

        void init();
    public:
        void windowLoop();
        void stopLoop();
        Window(const std::string& name, int width, int height) :
            width{width}, height{height},
            window{SDL_CreateWindow(name.c_str(), width, height, SDL_WINDOW_OPENGL)},
            glContext{SDL_GL_CreateContext(window)} { init(); }
        ~Window();
        void update();

        int GetWindowId() const { return SDL_GetWindowID(window); }
    };
} // namespace RixinSDL
