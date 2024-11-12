#pragma once

namespace LyndsayUI {
    class IEventPoller {
    public:
        virtual ~IEventPoller() {}
        //  Public stuff here
        virtual void PollEvents() = 0;
    };
} // LyndsayUI
