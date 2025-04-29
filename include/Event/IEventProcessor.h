#pragma once

namespace NSLyndsayUI {
    class IEventProcessor {
    public:
        virtual ~IEventProcessor() {}
        //  Public stuff here
        virtual void PollAndProcessEvents() = 0;
        virtual void WaitAndProcessEvents() = 0;
    };
} // LyndsayUI
