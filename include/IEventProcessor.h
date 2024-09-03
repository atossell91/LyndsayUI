#pragma once

#include <memory>

#include "IEvent.h"

namespace RixinSDL {
    class IEventProcessor {
    public:
        using handlerFunc = std::function<void(std::unique_ptr<IEvent>)>;
        virtual ~IEventProcessor() {}
        //  Public stuff here
        virtual void addEventHandler(int evenId, handlerFunc func) = 0;
        virtual void processEvent(std::unique_ptr<IEvent> event) = 0;
    };
} // EventQueue
