#pragma once

#include <SDL3/SDL.h>
#include <list>
#include <string>
#include <iostream>
#include <memory>
#include <type_traits>

#include "LyndsayUIContext.h"
#include "Window/WindowManager.h"

#include "IUpdateable.h"

#include "Event/IEventManager.h"
#include "Event/IEventProcessor.h"

#include "ILyndsayDependencyFactory.h"

#include "IIndexResolver.h"

#include "Window/CustomWindowBase.h"

namespace NSLyndsayUI {
   class LyndsayUI {
   private:

      LyndsayUIContext gameContext;

      std::unique_ptr<IWindowManager> windowManager;
      std::unique_ptr<IWindowFactory> windowFactory;

      std::unique_ptr<IEventProcessor> eventManager;

      const int kMainLoopDelay = 5; // Milliseconds

      void initSDL();
      void init();
      void mainLoop();
      void update();
      void cleanup();

   public:
      LyndsayUI();
      LyndsayUI(ILyndsayDependencyFactory* depFactory) : 
         windowManager{std::move(depFactory->GetWindowManager())},
         eventManager{std::move(depFactory->GetEventProcessor())},
         windowFactory{std::move(depFactory->GetWindowFactory())}
         { initSDL(); }

      void Run();

      //template <typename T>
      template <typename T, std::enable_if_t<std::is_base_of<CustomWindowBase, T>::value, bool> = true>
      std::unique_ptr<T> CreateWindow() {
         auto win = std::make_unique<T>();

         auto winType = windowFactory->CreateAsynchronousWindow();

         win->window.reset(winType.release());
      
         return std::move(win);
      }
   };
}