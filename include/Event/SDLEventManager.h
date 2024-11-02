#pragma once

#include <SDL3/SDL.h>

#include <list>
#include <functional>
#include <memory>

#include "Event/IEventManager.h"
#include "Event/IEventFactory.h"
#include "Event/IEventRouter.h"

namespace RixinSDL {
    class SDLEventManager : public IEventManager {
    private:
        std::shared_ptr<IEventFactory> eventFactory;
        std::shared_ptr<IEventRouter> eventRouter;
    public:
        //  Public stuff here
        void ProcessEvents();
        void HandleEvent(SDL_Event&);

        SDLEventManager(std::shared_ptr<IEventFactory> factory, std::shared_ptr<IEventRouter> router) : 
            eventFactory {factory}, eventRouter {router} {}
    };
} // RixinSDL
