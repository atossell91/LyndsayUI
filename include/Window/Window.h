#pragma once

#include <string>
#include <thread>
#include <list>
#include <vector>
#include <memory>

#include <SDL3/SDL.h>

#include "glad/glad.h"
#include "Drawing/BufferedImage.h"
#include "Drawing/DrawableBase.h"
#include "ShaderUtils.h"
#include "Event/EventQueue.h"
#include "Promise.h"
#include "Drawing/IGraphics.h"
#include "Drawing/GlGraphics.h"
#include "Drawing/DrawableCollection.h"

namespace NSLyndsayUI
{
    class Window
    {
    private:
        int width;
        int height;

        bool windowRunning = true;

        SDL_Window* window;
        SDL_GLContext glContext;
        std::unique_ptr<IGraphics> graphics;

        DrawableCollection drawables;

        std::unique_ptr<IEventQueue> eventQueue;

        void init();
    public:
        void windowLoop();
        void stopLoop();
        Window(const std::string& name, int width, int height) :
            width{width}, height{height},
            window{SDL_CreateWindow(name.c_str(), width, height, SDL_WINDOW_OPENGL)},
            glContext{SDL_GL_CreateContext(window)},
            eventQueue{std::make_unique<EventQueue>()},
            graphics{std::unique_ptr<IGraphics>(new GlGraphics(window))}
            { init(); }
        ~Window();
        void update();

        void SetCurrentContext() { SDL_GL_MakeCurrent(window, glContext); }

        int GetWindowId() const { return SDL_GetWindowID(window); }
        IEventQueue& GetEventQueue();
        DrawableCollection& GetDrawableCollection() {
            return drawables;
        }
        
        int AddShaderProgram(const std::string& vertex, const std::string& fragment) {
            SDL_GL_MakeCurrent(window, glContext);
            return ShaderUtils::BuildShaderProgram(vertex, fragment);
        }

        void AddImageToBuffer(const std::string& path,
            EmilyPromise::Promise<NSLyndsayUI::BufferedImage>& promise);
    };
} // namespace NSLyndsayUI
