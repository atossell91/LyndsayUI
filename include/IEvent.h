#pragma once

namespace RixinSDL {
    class IEvent {
    private:
        //  Private stuff here
        int eventType;
    public:
        //  Public stuff here
        IEvent(int type) : eventType{type} {}
        int getType() const { return eventType; }
    };
} // EventQueue
