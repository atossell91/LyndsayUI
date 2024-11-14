#pragma once

#include <SDL3/SDL.h>
#include <list>
#include <string>
#include <iostream>
#include <memory>

#include "LyndsayUIContext.h"
#include "Window/WindowManager.h"

#include "IUpdateable.h"

#include "Event/IEventFactory.h"
#include "Event/EventFactory.h"
#include "Event/IEventTent.h"
#include "Event/IEventManager.h"

#include "IIndexResolver.h"

namespace LyndsayUI {
   class LyndsayUI {
   private:

      LyndsayUIContext gameContext;

      std::unique_ptr<WindowManager> windowManager;

      std::shared_ptr<IIndexResolver> windowResolver;
      std::shared_ptr<IEventFactory> eventFactory;

      std::unique_ptr<IEventManager> eventManager;

      const int kMainLoopDelay = 5; // Milliseconds

      std::list<IUpdateable*> updateables;

      void initSDL();
      void initOpenGl();
      void init();
      void registerEvents();
      void mainLoop();
      void update();
      void cleanup();

   public:
      LyndsayUI();

      void Run();
      void AddUpdateable(IUpdateable* updateable);
      void RemoveUpdateable(IUpdateable* updateable);
      LyndsayUIContext& GetLyndsayUIContext() { return gameContext; }
      WindowManager* GetWindowManager() { return windowManager.get(); }
   };
}