#pragma once

#include <string>

#include "IEvent.h"

namespace RixinSDL {
    class MimiEvent : public EventQueue::IEvent {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        MimiEvent() : IEvent(5) {}
        std::string Name = "Mimi!";
    };
} // EventQueue
