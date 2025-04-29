#pragma once

#include <queue>
#include <memory>
#include <mutex>

#include "Event/IQueuedEventData.h"

namespace NSLyndsayUI {
    class IEventQueue {
    public:
        virtual ~IEventQueue() {}
        //  Public stuff here
        virtual void QueueEvent(std::unique_ptr<IQueuedEventData> event) = 0;
        virtual std::unique_ptr<IQueuedEventData> PollEventData() = 0;
        virtual std::unique_ptr<IQueuedEventData> WaitForEventData() = 0;
    };
} // EventQueue
