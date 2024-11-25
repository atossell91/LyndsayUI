#pragma once

#include <queue>
#include <memory>
#include <mutex>

#include "Event/IEventData.h"

namespace LyndsayUI {
    class IEventQueue {
    public:
        virtual ~IEventQueue() {}
        //  Public stuff here
        virtual void QueueEvent(std::unique_ptr<IEventData> event) = 0;
        virtual std::unique_ptr<IEventData> PollEventData() = 0;
    };
} // EventQueue
