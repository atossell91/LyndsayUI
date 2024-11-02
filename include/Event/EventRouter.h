#pragma once

#include <memory>

#include "Event/IEvent.h"
#include "Event/IEventRouter.h"

namespace RixinSDL {
    class EventRouter : public IEventRouter {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        void RouteEvent(std::unique_ptr<IEvent> event);
    };
} // RixinSDL
