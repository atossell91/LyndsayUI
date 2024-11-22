#pragma once

#include <memory>

#include "Event/IEvent.h"

namespace LyndsayUI {
    class IEventPusher {
    public:
        virtual ~IEventPusher() {}
        //  Public stuff here
        virtual void PushEvent(std::unique_ptr<IEvent> event) = 0;
    };
} // LyndsayUI
