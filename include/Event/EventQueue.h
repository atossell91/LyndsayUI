#pragma once

#include <queue>
#include <memory>
#include <mutex>

#include "Event/IEventData.h"
#include "Event/IEventQueue.h"

namespace LyndsayUI {
    class EventQueue : public IEventQueue {
    private:
        //  Private stuff here
        std::mutex mutex;
        std::queue<std::unique_ptr<IEventData>> eventQueue;
    public:
        //  Public stuff here
        void QueueEvent(std::unique_ptr<IEventData> eventData);
        std::unique_ptr<IEventData> PollEventData();
    };
} // EventQueue
