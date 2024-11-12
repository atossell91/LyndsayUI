#pragma once

#include <memory>

#include "Event/IEvent.h"

namespace LyndsayUI {
    class IEventReceiver {
    public:
        virtual ~IEventReceiver() {}
        //  Public stuff here
        virtual void RecieveEvent(std::unique_ptr<IEvent> event) = 0;
    };
} // LyndsayUI
