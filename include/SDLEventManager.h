#pragma once

#include <SDL3/SDL.h>

#include <list>
#include <functional>
#include <memory>

#include "IEventManager.h"
#include "IEventFactory.h"

namespace RixinSDL {
    class SDLEventManager : public IEventManager {
    private:
        std::shared_ptr<IEventFactory> eventFactory;
    public:
        //  Public stuff here
        void ProcessEvents();
        void HandleEvent(SDL_Event&);

        SDLEventManager(std::shared_ptr<IEventFactory> factory) : eventFactory {factory} {}
    };
} // RixinSDL
