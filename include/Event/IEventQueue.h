#pragma once

#include <queue>
#include <memory>
#include <mutex>

#include "Event/IEvent.h"

namespace RebeccaUI {
    class IEventQueue {
    public:
        virtual ~IEventQueue() {}
        //  Public stuff here
        virtual void queueEvent(std::unique_ptr<IEvent> event) = 0;
        virtual std::unique_ptr<IEvent> getEvent() = 0;
    };
} // EventQueue
