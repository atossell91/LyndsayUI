#include "Event/EventTent.h"

using namespace RebeccaUI;

//  Declare functions here
void EventTent::RecieveEvent(std::unique_ptr<IEvent> event) {
    auto iter = eventMap.find(event->getType());
    if (iter != eventMap.end()) {
        iter->second(std::move(event));
    }
}

void EventTent::AddEventResponse(int eventType, std::function<void(std::unique_ptr<IEvent>)> func) {
    eventMap[eventType] = func;
}
