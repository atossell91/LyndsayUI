#pragma once

namespace LyndsayUI {
    class IEventManager {
    public:
        virtual ~IEventManager() {}
        //  Public stuff here
        virtual void ProcessEvents() = 0;
    };
} // LyndsayUI
