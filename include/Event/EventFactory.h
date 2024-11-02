#pragma once

#include <functional>
#include <memory>
#include <unordered_map>

#include "Event/IEvent.h"
#include "Event/IEventFactory.h"

namespace RixinSDL {
    class EventFactory : public IEventFactory {
    private:
        //  Private stuff here
        std::unordered_map<int, EventFunc> eventFactories;
        EventFactory() {}
    public:
        //  Public stuff here
        static EventFactory& factory() {
            static EventFactory fac;
            return fac;
        }

        std::unique_ptr<IEvent> createEvent(int eventId);
        bool registerEvent(int eventId, EventFunc func);
    };
} // EventQueue