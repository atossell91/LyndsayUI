#pragma once

#include <SDL3/SDL.h>

#include <list>
#include <functional>
#include <memory>

#include "Event/IEventManager.h"
#include "Event/IEventFactory.h"
#include "Event/IEventRouter.h"
#include "IIndexResolver.h"

namespace RebeccaUI {
    class SDLEventManager : public IEventManager {
    private:
        std::shared_ptr<IEventFactory> eventFactory;
        std::shared_ptr<IEventRouter> eventRouter;
        std::shared_ptr<IIndexResolver> windowResolver;
    public:
        //  Public stuff here
        void ProcessEvents();
        void HandleEvent(SDL_Event&);

        SDLEventManager(std::shared_ptr<IEventFactory> factory, std::shared_ptr<IEventRouter> router, std::shared_ptr<IIndexResolver> resolver) : 
            eventFactory {factory}, eventRouter {router}, windowResolver{resolver} {}
    };
} // RebeccaUI
