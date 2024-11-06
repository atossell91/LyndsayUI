#pragma once

#include <memory>
#include <functional>
#include <unordered_map>

#include "Event/IEvent.h"
#include "Event/IEventProcessor.h"

namespace RebeccaUI {
    class EventProcessor : public IEventProcessor {
    private:
        //  Private stuff here
        std::unordered_map<int, handlerFunc> eventHandlers;
    public:
        //  Public stuff here
        void addEventHandler(int evenId, handlerFunc func);
        void processEvent(std::unique_ptr<IEvent> event);
    };
} // EventQueue
