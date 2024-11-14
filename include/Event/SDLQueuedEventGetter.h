#pragma once

#include <memory>

#include "Event/IEvent.h"
#include "Event/IEventFactory.h"
#include "Event/IQueuedEventGetter.h"

namespace LyndsayUI {
    class SDLQueuedEventGetter : public IQueuedEventGetter{
    private:
        //  Private stuff here
        std::unique_ptr<IEventFactory> eventFactory;
    public:
        //  Public stuff here
        std::unique_ptr<IEvent> GetQueuedEvent();
    };
} // LyndsayUI
