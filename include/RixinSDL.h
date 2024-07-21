#pragma once

#include <SDL3/SDL.h>
#include <list>
#include <string>
#include <iostream>

#include "RixinSDLContext.h"
#include "EventDispatcher.h"
#include "WindowStuff/WindowManager.h"

#include "interfaces/IUpdateable.h"

namespace RixinSDL {
   class RixinSDL {
   private:

      RixinSDLContext gameContext;
      EventDispatcher eventDispatcher;
      WindowManager windowManager;

      std::string defaultWindowTitle = "Rixin Window";

      const int kMainLoopDelay = 20; // Milliseconds

      std::list<IUpdateable*> updateables;

      void init();
      void mainLoop();
      void processEvents();
      void update();
      void cleanup();

   public:
      RixinSDL();

      void Run();
      void AddUpdateable(IUpdateable* updateable);
      void RemoveUpdateable(IUpdateable* updateable);
      RixinSDLContext& GetRixinSDLContext() { return gameContext; }
      EventDispatcher& GetEventDispatcher() { return eventDispatcher; }
      WindowManager& GetWindowManager() { return windowManager; }
   };
}