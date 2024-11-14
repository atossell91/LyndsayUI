#pragma once

#include <memory>

#include "Event/IEvent.h"
#include "Event/IEventFactory.h"

namespace LyndsayUI {
    class SDLQueuedEventGetter {
    private:
        //  Private stuff here
        std::unique_ptr<IEventFactory> eventFactory;
    public:
        //  Public stuff here
        std::unique_ptr<IEvent> GetQueuedEvent();
    };
} // LyndsayUI
