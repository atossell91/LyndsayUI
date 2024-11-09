#pragma once

#include <SDL3/SDL.h>

#include <list>
#include <functional>
#include <memory>

#include "Event/IEventReceiver.h"
#include "Event/IEventManager.h"
#include "Event/IEventFactory.h"
#include "IIndexResolver.h"

namespace RebeccaUI {
    class SDLEventManager : public IEventManager {
    private:
        std::shared_ptr<IEventFactory> eventFactory;
        std::shared_ptr<IIndexResolver> windowResolver;
        IEventReceiver* receiver;
    public:
        //  Public stuff here
        void ProcessEvents();
        void HandleEvent(SDL_Event&);

        SDLEventManager(
            std::shared_ptr<IEventFactory> factory,
            std::shared_ptr<IIndexResolver> resolver,
            IEventReceiver* receiver) : 
            eventFactory {factory},
            windowResolver{resolver}
            {}
    };
} // RebeccaUI
