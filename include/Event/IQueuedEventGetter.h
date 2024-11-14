#pragma once

#include <memory>

#include "Event/IEvent.h"
#include "Event/IQueuedEventGetter.h"

namespace LyndsayUI {
    class IQueuedEventGetter {
    public:
        virtual ~IQueuedEventGetter() {}
        //  Public stuff here
        virtual std::unique_ptr<IEvent> GetQueuedEvent() = 0;
    };
} // LyndsayUI
