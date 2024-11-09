#pragma once

#include <memory>
#include <functional>

#include "Event/IEvent.h"
#include "Event/IEventReceiver.h"

namespace RebeccaUI {
    class IEventTent : public IEventReceiver {
    public:
        virtual ~IEventTent() {}
        //  Public stuff here
        virtual void RecieveEvent(std::unique_ptr<IEvent> event) = 0;
        virtual void AddEventResponse(int eventType, std::function<void(std::unique_ptr<IEvent>)> func) = 0;
    };
} // RebeccaUI
