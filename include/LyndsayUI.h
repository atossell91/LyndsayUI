#pragma once

#include <list>
#include <string>
#include <iostream>
#include <memory>
#include <type_traits>

#include "LyndsayUIContext.h"

#include "IUpdateable.h"

#include "Event/IEventManager.h"
#include "Event/IEventProcessor.h"

#include "ILyndsayDependencyFactory.h"
#include "SDLLyndsayDependencyFactory.h" 

#include "Window/IWindowCollection.h"
#include "Window/Window.h"
#include "Window/WindowFactory.h"

namespace NSLyndsayUI {
   class LyndsayUI {
   private:

      LyndsayUIContext gameContext;

      std::unique_ptr<IWindowFactory> windowFactory;
      std::unique_ptr<IWindowEventCoordinator> eventManager;
      std::unique_ptr<WindowFactory> customWinFactory;

      std::unique_ptr<IWindowCollection<Window>> windows;

      const int kMainLoopDelay = 5; // Milliseconds

      void initSDL();
      void init();
      void immediateLoop();
      void retainedLoop();
      void update();
      void cleanup();

   public:
      LyndsayUI() {

            std::unique_ptr<ILyndsayDependencyFactory> fac = std::make_unique<SDLLyndsayDependencyFactory>();
            eventManager = std::move(fac->GetEventProcessor());
            customWinFactory = std::move(fac->GetWindowFactory());
            windows = std::move(fac->GetWindowCollection());

            initSDL();
            init();
         }

      template <typename T>
      void AddWindow() {
         auto win = customWinFactory->CreateWindow<T>();
         windows->AddWindow(std::move(win));
      }

      void RunImmediate();
      void RunRetained();
   };
}