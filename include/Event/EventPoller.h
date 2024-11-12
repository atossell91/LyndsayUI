#pragma once

#include "Event/IEventPoller.h"
#include "Event/IEventReceiver.h"
#include "Event/IEventQueue.h"

namespace LyndsayUI {
    class EventPoller : public IEventPoller {
    private:
        //  Private stuff here
        IEventReceiver* eventTent = nullptr;
        IEventQueue* eventQueue = nullptr;
    public:
        //  Public stuff here
        EventPoller(IEventReceiver* evTent, IEventQueue* queue) : eventTent{evTent}, eventQueue{queue} {}
        void PollEvents();
    };
} // LyndsayUI
