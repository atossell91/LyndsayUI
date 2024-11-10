#include "Event/EventTent.h"

#include <iostream>

using namespace RebeccaUI;

//  Declare functions here
void EventTent::RecieveEvent(std::unique_ptr<IEvent> event) {
    std::cout << "Receiver - Getting event type" << std::endl;
    auto iter = eventMap.find(event->getType());

    std::cout << "Searching the map" << std::endl;
    if (iter != eventMap.end()) {
        std::cout << "Forwarding the event" << std::endl;
        iter->second(std::move(event));
    }
    else {
        std::cout << "Event type not in map" << std::endl;
    }
}

void EventTent::AddEventResponse(int eventType, std::function<void(std::unique_ptr<IEvent>)> func) {
    eventMap[eventType] = func;
}
