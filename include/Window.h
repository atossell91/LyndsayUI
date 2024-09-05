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
#include "EventQueue.h"
#include "EventProcessor.h"
#include "Promise.h"

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

        std::unique_ptr<IEventQueue> eventQueue;
        std::unique_ptr<IEventProcessor> eventProcessor;

        void init();
    public:
        void windowLoop();
        void stopLoop();
        Window(const std::string& name, int width, int height) :
            width{width}, height{height},
            window{SDL_CreateWindow(name.c_str(), width, height, SDL_WINDOW_OPENGL)},
            glContext{SDL_GL_CreateContext(window)},
            eventProcessor{std::make_unique<EventProcessor>()},
            eventQueue{std::make_unique<Queue>()}
            { init(); }
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
        IEventQueue& GetEventQueue();
        IEventProcessor& GetEventProcessor();
        BufferedImage bufferImage(const std::string& imgPath);

        //Called from main thread (probably)
        promise<BufferedImage> bufferImage2(const std::string& imgPath);

    };
} // namespace RixinSDL
