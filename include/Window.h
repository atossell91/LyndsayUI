#pragma once

#include <string>
#include <thread>
#include <list>
#include <vector>

#include <SDL3/SDL.h>

#include "glad/glad.h"
#include "BufferedImage.h"
#include "DrawableBase.h"
#include "ShaderUtils.h"

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

        std::list<std::unique_ptr<DrawableBase>> drawables;

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
        void AddDrawable(std::unique_ptr<DrawableBase> drawable) {
            drawables.push_back(std::move(drawable));
        }
        
        int AddShaderProgram(const std::string& vertex, const std::string& fragment) {
            SDL_GL_MakeCurrent(window, glContext);
            return ShaderUtils::BuildShaderProgram(vertex, fragment);
        }

        void SetCurrentContext() { SDL_GL_MakeCurrent(window, glContext); }

        int GetWindowId() const { return SDL_GetWindowID(window); }
        RixinSDL::BufferedImage bufferImage(const std::string& imgPath);

        void LudoVica();
    };
} // namespace RixinSDL
