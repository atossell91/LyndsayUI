#pragma once

#include "Event/EventTypes.h"
#include "Event/EventBase.h"

namespace RixinSDL {
    class CloseButtonPressedEvent : public EventBase {
    private:
        //  Private stuff here
        int destinationId;
    public:
        //  Public stuff here
        CloseButtonPressedEvent() : EventBase(EventTypes::CLOSE_BUTTON_PRESSED_EVENT) {}
        int GetDestinationID() { return destinationId; }
        void SetDestinationID(int destination ) { destinationId = destination; }
    };
} // RixinSDL
