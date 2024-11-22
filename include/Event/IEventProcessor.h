#pragma once

namespace LyndsayUI {
    class IEventProcessor {
    public:
        virtual ~IEventProcessor() {}
        //  Public stuff here
        virtual void ProcessEvents() = 0;
    };
} // LyndsayUI
