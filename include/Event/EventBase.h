#pragma once

#include "Event/IEvent.h"

namespace LyndsayUI {
    class EventBase : public IEvent {
    protected:
        //  Private stuff here
        int eventType;
    public:
        //  Public stuff here
        EventBase(int type) : eventType{type} {}
        int getType() const { return eventType; }
    };
} // LyndsayUI
