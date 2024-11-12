#pragma once

#include <queue>
#include <memory>
#include <mutex>

#include "Event/IEvent.h"
#include "Event/IEventQueue.h"

namespace LyndsayUI {
    class EventQueue : public IEventQueue {
    private:
        //  Private stuff here
        std::mutex mutex;
        std::queue<std::unique_ptr<IEvent>> eventQueue;
    public:
        //  Public stuff here
        void QueueEvent(std::unique_ptr<IEvent> event);
        std::unique_ptr<IEvent> GetEvent();
    };
} // EventQueue
