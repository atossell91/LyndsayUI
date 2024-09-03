#include "EventProcessor.h"

using namespace RixinSDL;

//  Declare functions here
void EventProcessor::processEvent(std::unique_ptr<IEvent> event) {
    auto func = eventHandlers.find(event->getType());

    if (func != eventHandlers.end()) {
        func->second(std::move(event));
    }
}
