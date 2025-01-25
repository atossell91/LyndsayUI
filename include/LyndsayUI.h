#pragma once

#include <SDL3/SDL.h>
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

#include "Window/RetainedWindow.h"
#include "Window/ImmediateWindow.h"
#include "Window/IWindowCollection.h"
#include "Window/CustomWindowFactory.h"

namespace NSLyndsayUI {
   class LyndsayUI {
   private:

      LyndsayUIContext gameContext;

      std::unique_ptr<IWindowFactory> windowFactory;
      std::unique_ptr<IWindowEventCoordinator> eventManager;
      std::unique_ptr<CustomWindowFactory> customWinFactory;

      std::unique_ptr<IWindowCollection<RetainedWindow>> retainedWindows;
      std::unique_ptr<IWindowCollection<ImmediateWindow>> immediateWindows;

      const int kMainLoopDelay = 5; // Milliseconds

      void initSDL();
      void init();
      void mainLoop();
      void update();
      void cleanup();

   public:
      LyndsayUI() {

            std::unique_ptr<ILyndsayDependencyFactory> fac = std::make_unique<SDLLyndsayDependencyFactory>();
            eventManager = std::move(fac->GetEventProcessor());
            customWinFactory = std::move(fac->GetCustomWindowFactory());
            immediateWindows = std::move(fac->GetImmediateWindowCollection());
            retainedWindows = std::move(fac->GetRetainedWindowCollection());

            initSDL();
            init();
         }

      template <typename T>
      void AddImmediateWindow() {
         auto win = customWinFactory->CreateImmediateWindow<T>();
         immediateWindows->AddWindow(std::move(win));
      }

      //template <typename T>
      //void AddRetainedWindow() {
         //auto win = customWinFactory->CreateRetainedWindow<T>();
         //retainedWindows(std::move(win));
      //}

      void Run();
   };
}