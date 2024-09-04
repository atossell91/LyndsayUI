#pragma once

#include "IEvent.h"

namespace RixinSDL {
    class TestEvent : public IEvent {
    private:
        int eventType;
    public:
        //  Public stuff here
        TestEvent() : eventType{91} {}
        TestEvent(int type) : eventType{type} {}
        int getType() const { return eventType; }
    };
} // RixinSDL
