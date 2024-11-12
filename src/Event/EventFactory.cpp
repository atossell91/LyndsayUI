#include "Event/EventFactory.h"

using namespace LyndsayUI;

#include <iostream>

//  Declare functions here
std::unique_ptr<IEvent> EventFactory::createEvent(int eventId) {
    auto facIter = eventFactories.find(eventId);
    if (facIter != eventFactories.end()) {
        auto evPtr = facIter->second();
        return evPtr;
    }
    else {
        std::cout << "The event ID lookup failed. Is the event registered?" << std::endl;
        return nullptr;
    }
}

bool EventFactory::registerEvent(int eventId, EventFunc func) {
    auto facIter = eventFactories.find(eventId);
    if (facIter != eventFactories.end()) {
        return false;
    }
    else {
        eventFactories.emplace(eventId, func);
        return true;
    }
}
