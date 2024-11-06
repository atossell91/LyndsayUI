#include "Event/EventProcessor.h"

using namespace RebeccaUI;

//  Declare functions here
void EventProcessor::addEventHandler(int eventId, handlerFunc func) {
    auto funcIter = eventHandlers.find(eventId);
    if (funcIter == eventHandlers.end()) {
        eventHandlers.emplace(eventId, func);
    }
    else {
        //  Did not add event, because it's already present.
    }
}

void EventProcessor::processEvent(std::unique_ptr<IEvent> event) {
    auto func = eventHandlers.find(event->getType());

    if (func != eventHandlers.end()) {
        func->second(std::move(event));
    }
}
