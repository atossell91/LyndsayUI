#pragma once

#include <queue>
#include <memory>
#include <mutex>

#include "Event/IQueuedEventData.h"
#include "Event/IEventQueue.h"

namespace LyndsayUI {
    class EventQueue : public IEventQueue {
    private:
        //  Private stuff here
        std::mutex mutex;
        std::queue<std::unique_ptr<IQueuedEventData>> eventQueue;
    public:
        //  Public stuff here
        void QueueEvent(std::unique_ptr<IQueuedEventData> eventData);
        std::unique_ptr<IQueuedEventData> PollEventData();
    };
} // EventQueue
