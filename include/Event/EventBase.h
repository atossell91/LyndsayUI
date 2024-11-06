#pragma once

#include "Event/IEvent.h"

namespace RebeccaUI {
    class EventBase : public IEvent {
    protected:
        //  Private stuff here
        int eventType;
    public:
        //  Public stuff here
        EventBase(int type) : eventType{type} {}
        virtual int getType() const { return eventType; }
    };
} // RebeccaUI
