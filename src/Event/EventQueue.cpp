#include "Event/EventQueue.h"
#include "Event/IEvent.h"

#include <memory>

using namespace RixinSDL;

//  Declare functions here
void Queue::queueEvent(std::unique_ptr<IEvent> event) {
    std::lock_guard<std::mutex> lock(mutex);
    eventQueue.push(std::move(event));
}

std::unique_ptr<IEvent> Queue::getEvent() {
    std::lock_guard<std::mutex> lock(mutex);
    if (!eventQueue.empty()) {
        auto ptr = std::move(eventQueue.front());
        eventQueue.pop();
        return ptr;
    }
    else {
        return nullptr;
    }
}
