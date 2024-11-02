#pragma once

#include <SDL3/SDL.h>
#include <list>
#include <string>
#include <iostream>

#include "RixinSDLContext.h"
#include "Window/WindowManager.h"
#include "Event/IEventManager.h"

#include "IUpdateable.h"

namespace RixinSDL {
   class RixinSDL {
   private:

      RixinSDLContext gameContext;
      WindowManager windowManager;

      std::unique_ptr<IEventManager> eventManager;

      const int kMainLoopDelay = 5; // Milliseconds

      std::list<IUpdateable*> updateables;

      void initSDL();
      void initOpenGl();
      void init();
      void mainLoop();
      void update();
      void cleanup();

   public:
      RixinSDL();

      void Run();
      void AddUpdateable(IUpdateable* updateable);
      void RemoveUpdateable(IUpdateable* updateable);
      RixinSDLContext& GetRixinSDLContext() { return gameContext; }
      WindowManager& GetWindowManager() { return windowManager; }
   };
}