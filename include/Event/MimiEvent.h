#pragma once

#include <string>

#include "Event/IEvent.h"

namespace RebeccaUI {
    class MimiEvent : public EventQueue::IEvent {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        MimiEvent() : IEvent(5) {}
        std::string Name = "Mimi!";
    };
} // EventQueue
