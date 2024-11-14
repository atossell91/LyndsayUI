#pragma once

#include <memory>

#include "Event/IEventManager.h"
#include "Event/IEvent.h"
#include "Event/IQueuedEventGetter.h"
#include "Event/IEventTent.h"

namespace LyndsayUI {
    class LyndsayEventManager {
    private:
        //  Private stuff here
        std::unique_ptr<IQueuedEventGetter> eventGetter;
        std::unique_ptr<IEventTent> eventTent;
    public:
        //  Public stuff here
        LyndsayEventManager(
            std::unique_ptr<IQueuedEventGetter> evGetter,
            std::unique_ptr<IEventTent> evTent) :
            eventGetter{std::move(evGetter)}, eventTent{std::move(evTent)} {}

        void ProcessEvents();
    };
} // LyndsayUI
