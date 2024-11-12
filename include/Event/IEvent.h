#pragma once

namespace LyndsayUI {
    class IEvent {
    public:
        virtual ~IEvent() {}
        virtual int getType() const = 0;
    };
} // EventQueue
