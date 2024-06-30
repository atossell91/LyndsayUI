#pragma once

#include <SDL3/SDL.h>
#include <list>

#include "RixinSDLContext.h"
#include "EventDispatcher.h"

#include "interfaces/IDrawable.h"
#include "DrawManager.h"

#include "interfaces/IUpdateable.h"

namespace RixinSDL {
   class RixinSDL {
   private:
      const int kInitFlags = SDL_INIT_VIDEO;

      const int kWindowWidth = 1920;
      const int kWindowHeight = 1080;
      const char* gameName = "Rubber Duck";

      SDL_Window* window;

      RixinSDLContext gameContext;
      EventDispatcher eventDispatcher;
      DrawManager drawManager;

      const int kMainLoopDelay = 20; // Milliseconds

      std::list<IUpdateable*> updateables;

      void init();
      void mainLoop();
      void processEvents();
      void update();
      void cleanup();

   public:
      RixinSDL() : 
      window{SDL_CreateWindow(gameName, kWindowWidth, kWindowHeight, 0)},
      drawManager{DrawManager::CreateFromWindow(window)} {}

      void Run();
      void AddDrawable(IDrawable* drawable);
      void RemoveDrawable(IDrawable* drawable);
      void AddUpdateable(IUpdateable* updateable);
      void RemoveUpdateable(IUpdateable* updateable);
      RixinSDLContext& GetRixinSDLContext();
      EventDispatcher& GetEventDispatcher();
   };
}