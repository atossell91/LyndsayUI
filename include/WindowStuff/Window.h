#pragma once

#include <string>

#include <SDL3/SDL.h>

#include "glad/glad.h"

namespace RixinSDL
{
    class Window
    {
    private:
        int width;
        int height;

        SDL_Window* window;
        SDL_GLContext glContext;

        void init();
    public:
        Window(const std::string& name, int width, int height) :
            width{width}, height{height},
            window{SDL_CreateWindow(name.c_str(), width, height, SDL_WINDOW_OPENGL)},
            glContext{SDL_GL_CreateContext(window)} { init(); }
        ~Window() { SDL_DestroyWindow(window); }
        void update();

        int GetWindowId() const { return SDL_GetWindowID(window); }
    };
} // namespace RixinSDL
