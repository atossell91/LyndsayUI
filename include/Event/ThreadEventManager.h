#pragma once

#include <memory>

#include "Event/IEventManager.h"
#include "Event/IQueuedEventData.h"
#include "Event/IEventQueue.h"

namespace NSLyndsayUI {
    class ThreadEventManager : public IEventManager {
    private:
        //  Private stuff here
        std::unique_ptr<IEventQueue> eventQueue;
    public:
        //  Public stuff here
        ThreadEventManager(
            std::unique_ptr<IEventQueue> evQueue) : 
            eventQueue{std::move(evQueue)} {}

        void ProcessEvents();
        void PushEvent(std::unique_ptr<IQueuedEventData> eventData);
    };
} // LyndsayUI
