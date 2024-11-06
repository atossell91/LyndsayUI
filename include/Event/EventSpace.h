#pragma once

#include "Event/EventTypes.h"
#include "Event/EventBase.h"

namespace RebeccaUI {
    class CloseButtonPressedEvent : public EventBase {
    private:
        //  Private stuff here
        int windowId;
    public:
        //  Public stuff here
        CloseButtonPressedEvent() : EventBase(EventTypes::CLOSE_BUTTON_PRESSED_EVENT) {}
        int GetWindowID() { return windowId; }
        void SetWindowID(int destination ) { windowId = destination; }
    };
} // RebeccaUI
