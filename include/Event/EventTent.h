#pragma once

#include <map>
#include <memory>
#include <functional>

#include "Event/IEvent.h"
#include "Event/IEventTent.h"

namespace LyndsayUI {
    class EventTent : public IEventTent {
    private:
        //  Private stuff here
        std::map<int, std::function<void(std::unique_ptr<IEvent>)>> eventMap;
    public:
        //  Public stuff here
        void RecieveEvent(std::unique_ptr<IEvent> event);
        void AddEventResponse(int eventType, std::function<void(std::unique_ptr<IEvent>)> func);
    };
} // LyndsayUI
