#pragma once

#include <SDL3/SDL.h>
#include <list>

#include "RixinSDLContext.h"
#include "EventDispatcher.h"
#include "interfaces/IDrawable.h"
#include "interfaces/IUpdateable.h"

class RixinSDL {
 private:
    const int kInitFlags = SDL_INIT_VIDEO;

    RixinSDLContext gameContext;
    EventDispatcher eventDispatcher;

    const int kWindowWidth = 1920;
    const int kWindowHeight = 1080;
    const char* gameName = "Rubber Duck";

    const int kMainLoopDelay = 20; // Milliseconds

    SDL_Window* window;
    SDL_Renderer* renderer;

    std::list<IDrawable*> drawables;
    std::list<IUpdateable*> updateables;

    void init();
    void mainLoop();
    void processEvents();
    void update();
    void draw();
    void cleanup();

 public:
    RixinSDL();
    void Run();
    void AddDrawable(IDrawable* drawable);
    void RemoveDrawable(IDrawable* drawable);
    void AddUpdateable(IUpdateable* updateable);
    void RemoveUpdateable(IUpdateable* updateable);
    RixinSDLContext& GetRixinSDLContext();
    EventDispatcher& GetEventDispatcher();
    SDL_Texture* LoadTexture(const char* path);
};