#include "Event/EventQueue.h"
#include "Event/IEventData.h"

#include <memory>

using namespace LyndsayUI;

//  Declare functions here
void EventQueue::QueueEvent(std::unique_ptr<IEventData> event) {
    std::lock_guard<std::mutex> lock(mutex);
    eventQueue.push(std::move(event));
}

std::unique_ptr<IEventData> EventQueue::PollEventData() {
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
