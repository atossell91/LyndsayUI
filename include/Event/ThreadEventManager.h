#pragma once

#include <memory>

#include "Event/IEventManager.h"
#include "Event/IEvent.h"
#include "Event/IEventQueue.h"
#include "Event/IEventTent.h"

namespace LyndsayUI {
    class ThreadEventManager : public IEventManager {
    private:
        //  Private stuff here
        std::unique_ptr<IEventQueue> eventQueue;
        std::shared_ptr<IEventTent> eventTent;
    public:
        //  Public stuff here
        ThreadEventManager(
            std::unique_ptr<IEventQueue> evQueue,
            std::shared_ptr<IEventTent> evTent) : 
            eventQueue{std::move(evQueue)}, eventTent{evTent} {}

        void ProcessEvents();
        void PushEvent(std::unique_ptr<IEvent> event);
    };
} // LyndsayUI
