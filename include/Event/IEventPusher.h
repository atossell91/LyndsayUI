#pragma once

#include <memory>

#include "Event/IEventData.h"

namespace LyndsayUI {
    class IEventPusher {
    public:
        virtual ~IEventPusher() {}
        //  Public stuff here
        virtual void PushEvent(std::unique_ptr<IEventData> event) = 0;
    };
} // LyndsayUI
