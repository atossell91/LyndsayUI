#pragma once

#include <memory>
#include <functional>

#include "Event/IEvent.h"

namespace RebeccaUI {
    class IEventFactory {
    public:
        using EventFunc = std::function<std::unique_ptr<IEvent>()>;
        virtual ~IEventFactory() {}
        //  Public stuff here
        virtual std::unique_ptr<IEvent> createEvent(int eventId) = 0;
        virtual bool registerEvent(int eventId, EventFunc func) = 0;
    };
} // EventQueue
