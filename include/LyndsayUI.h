#pragma once

#include <SDL3/SDL.h>
#include <list>
#include <string>
#include <iostream>
#include <memory>

#include "LyndsayUIContext.h"
#include "Window/WindowManager.h"

#include "IUpdateable.h"

#include "Event/IEventManager.h"
#include "Event/IEventProcessor.h"

#include "ILyndsayDependencyFactory.h"

#include "IIndexResolver.h"

namespace LyndsayUI {
   class LyndsayUI {
   private:

      LyndsayUIContext gameContext;

      std::unique_ptr<IWindowManager> windowManager;

      std::unique_ptr<IEventProcessor> eventManager;

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
      LyndsayUI(ILyndsayDependencyFactory* depFactory) : 
         windowManager{std::move(depFactory->CreateWindowManager())},
         eventManager{std::move(depFactory->CreateEventProcessor())} 
         { initSDL(); }

      void Run();
      void AddUpdateable(IUpdateable* updateable);
      void RemoveUpdateable(IUpdateable* updateable);
      LyndsayUIContext& GetLyndsayUIContext() { return gameContext; }
      IWindowManager* GetWindowManager() { return windowManager.get(); }
   };
}