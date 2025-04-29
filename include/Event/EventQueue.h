#pragma once

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>

#include "Event/IQueuedEventData.h"
#include "Event/IEventQueue.h"

namespace NSLyndsayUI {
    class EventQueue : public IEventQueue {
    private:
        //  Private stuff here
        std::mutex mutex;
        std::queue<std::unique_ptr<IQueuedEventData>> eventQueue;
        std::condition_variable cv;
    public:
        //  Public stuff here
        void QueueEvent(std::unique_ptr<IQueuedEventData> eventData);
        std::unique_ptr<IQueuedEventData> PollEventData();
        std::unique_ptr<IQueuedEventData> WaitForEventData();
    };
} // EventQueue
