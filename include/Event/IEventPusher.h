#pragma once

#include <memory>

#include "Event/IQueuedEventData.h"

namespace LyndsayUI {
    class IEventPusher {
    public:
        virtual ~IEventPusher() {}
        //  Public stuff here
        virtual void PushEvent(std::unique_ptr<IQueuedEventData> event) = 0;
    };
} // LyndsayUI
