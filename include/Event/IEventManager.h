#pragma once

#include "Event/IEventProcessor.h"
#include "Event/IEventPusher.h"

namespace LyndsayUI {
    class IEventManager : public IEventProcessor, public IEventPusher {
    public:
        virtual ~IEventManager() {}
        //  Public stuff here
    };
} // LyndsayUI
