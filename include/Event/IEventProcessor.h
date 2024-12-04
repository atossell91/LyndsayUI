#pragma once

namespace NSLyndsayUI {
    class IEventProcessor {
    public:
        virtual ~IEventProcessor() {}
        //  Public stuff here
        virtual void ProcessEvents() = 0;
    };
} // LyndsayUI
