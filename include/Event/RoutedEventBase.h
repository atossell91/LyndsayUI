#pragma once

#include "Event/IEvent.h"
#include "Event/EventBase.h"

namespace RixinSDL {
    class RoutedEventBase : public EventBase {
    private:
        //  Private stuff here
        int eventDestination = 0;
    public:
        //  Public stuff here
        RoutedEventBase(int eventType) : EventBase(eventType) {}
        int GetEventDestination() const { return eventDestination; }
        void SetEventDestination(int destination) { eventDestination = destination; }
    };
} // RixinSDL
