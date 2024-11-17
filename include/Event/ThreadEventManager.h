#pragma once

#include <memory>

#include "Event/IEventManager.h"
#include "Event/IEvent.h"
#include "Event/IQueuedEventGetter.h"
#include "Event/IEventTent.h"

namespace LyndsayUI {
    class ThreadEventManager : public IEventManager {
    private:
        //  Private stuff here
        std::unique_ptr<IQueuedEventGetter> eventGetter;
        std::shared_ptr<IEventTent> eventTent;
    public:
        //  Public stuff here
        ThreadEventManager(
            std::unique_ptr<IQueuedEventGetter> evGetter,
            std::shared_ptr<IEventTent> evTent) :
            eventGetter{std::move(evGetter)}, eventTent{evTent} {}

        void ProcessEvents();
    };
} // LyndsayUI
