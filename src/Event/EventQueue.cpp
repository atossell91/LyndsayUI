#include "Event/EventQueue.h"
#include "Event/IEvent.h"

#include <memory>

using namespace LyndsayUI;

//  Declare functions here
void EventQueue::QueueEvent(std::unique_ptr<IEvent> event) {
    std::lock_guard<std::mutex> lock(mutex);
    eventQueue.push(std::move(event));
}

std::unique_ptr<IEvent> EventQueue::GetEvent() {
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
