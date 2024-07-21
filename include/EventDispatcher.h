#pragma once

#include <functional>
#include <list>
#include <SDL3/SDL.h>

namespace RixinSDL {
   class EventDispatcher {
   private:
      std::list<std::function<void(SDL_Keycode)>> keyDownHandlers;
      std::list<std::function<void(SDL_Keycode)>> keyUpHandlers;
      std::list<std::function<void(SDL_MouseButtonFlags)>> mouseButtonDownHandlers;
      std::list<std::function<void(SDL_MouseButtonFlags)>> mouseButtonUpHandlers;
      std::list<std::function<void(float posX, float posY)>> mouseMoveHandlers;
      std::list<std::function<void()>> quitHandlers;
      std::list<std::function<void(int)>> closeWindowHandlers;

   public:
      //  Assume SDL_KeyCode (for the up and down handlers)
      void AddKeyDownHandler(std::function<void(int)> handler);
      void AddKeyUpHandler(std::function<void(int)> handler);

      //  Assume SDL_MouseButtonFlags (for the up and down handlers)
      void AddMouseButtonDownHandler(std::function<void(int)> handler);
      void AddMouseButtonUpHandler(std::function<void(int)> handler);
      void AddMouseMoveHandler(std::function<void(float posX, float posY)> handler);
      void AddQuitHandler(std::function<void()> handler);

      void AddCloseWindowHandler(std::function<void(int)>handler);
      void HandleEvent(SDL_Event&);
   };
}
