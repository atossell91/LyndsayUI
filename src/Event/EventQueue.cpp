#include "Event/EventQueue.h"
#include "Event/IQueuedEventData.h"

#include <memory>

using namespace NSLyndsayUI;

//  Declare functions here
void EventQueue::QueueEvent(std::unique_ptr<IQueuedEventData> event) {
    std::lock_guard<std::mutex> lock(mutex);
    eventQueue.push(std::move(event));
}

std::unique_ptr<IQueuedEventData> EventQueue::PollEventData() {
    std::unique_lock<std::mutex> lock(mutex);
    if (!eventQueue.empty()) {
        auto ptr = std::move(eventQueue.front());
        eventQueue.pop();
        return ptr; 
    }
    else {
        return nullptr;
    }
    lock.unlock();
    cv.notify_all();
}

std::unique_ptr<IQueuedEventData> EventQueue::WaitForEventData() {
    std::unique_lock<std::mutex> lock(mutex);
    cv.wait(lock, [this]{ return !this->eventQueue.empty(); });
}
