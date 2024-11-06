#pragma once

#include <memory>

#include "Event/IEvent.h"

namespace RebeccaUI {
    class IEventRouter {
    public:
        virtual ~IEventRouter() {}
        //  Public stuff here

        virtual void RouteEvent(std::unique_ptr<IEvent> event) = 0;
    };
} // RebeccaUI
