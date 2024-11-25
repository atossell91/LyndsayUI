#pragma once

#include <memory>

#include "Event/IEventManager.h"
#include "Event/IEventData.h"
#include "Event/IEventQueue.h"

namespace LyndsayUI {
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
        void PushEvent(std::unique_ptr<IEventData> eventData);
    };
} // LyndsayUI
