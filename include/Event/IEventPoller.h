#pragma once

namespace RebeccaUI {
    class IEventPoller {
    public:
        virtual ~IEventPoller() {}
        //  Public stuff here
        virtual void PollEvents() = 0;
    };
} // RebeccaUI
