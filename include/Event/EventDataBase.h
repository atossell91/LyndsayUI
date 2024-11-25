#pragma once

#include "Event/IEventData.h"

namespace LyndsayUI {
    class EventDataBase : public IEventData {
    protected:
        //  Private stuff here
        int eventType;
    public:
        //  Public stuff here
        EventDataBase(int type) : eventType{type} {}
        int getEventType() const { return eventType; }
    };
} // LyndsayUI
