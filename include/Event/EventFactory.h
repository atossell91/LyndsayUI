#pragma once

#include <functional>
#include <memory>
#include <unordered_map>

#include "Event/IEvent.h"
#include "Event/IEventFactory.h"

namespace LyndsayUI {
    class EventFactory : public IEventFactory {
    private:
        //  Private stuff here
        std::unordered_map<int, EventFunc> eventFactories;
    public:
        //  Public stuff here
        std::unique_ptr<IEvent> createEvent(int eventId);
        bool registerEvent(int eventId, EventFunc func);
    };
} // EventQueue
