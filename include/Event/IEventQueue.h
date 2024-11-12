#pragma once

#include <queue>
#include <memory>
#include <mutex>

#include "Event/IEvent.h"

namespace LyndsayUI {
    class IEventQueue {
    public:
        virtual ~IEventQueue() {}
        //  Public stuff here
        virtual void QueueEvent(std::unique_ptr<IEvent> event) = 0;
        virtual std::unique_ptr<IEvent> GetEvent() = 0;
    };
} // EventQueue
