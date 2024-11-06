#pragma once

#include <memory>

#include "Event/IEvent.h"
#include "Event/IEventRouter.h"
#include "IIndexResolver.h"

namespace RebeccaUI {
    class EventRouter : public IEventRouter {
    private:
        //  Private stuff here
        std::shared_ptr<IIndexResolver> windowResolver;
    public:
        //  Public stuff here
        EventRouter(std::shared_ptr<IIndexResolver> resolver) : windowResolver{resolver} {}
        void RouteEvent(std::unique_ptr<IEvent> event);
    };
} // RebeccaUI
