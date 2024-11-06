#pragma once

namespace RebeccaUI {
    class IEventManager {
    public:
        virtual ~IEventManager() {}
        //  Public stuff here
        virtual void ProcessEvents() = 0;
    };
} // RebeccaUI
