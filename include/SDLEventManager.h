#pragma once

#include <SDL3/SDL.h>

#include <list>
#include <functional>

#include "IEventManager.h"

namespace RixinSDL {
    class SDLEventManager : public IEventManager {
    private:
    public:
        //  Public stuff here
        void ProcessEvents();
        void HandleEvent(SDL_Event&);
    };
} // RixinSDL
