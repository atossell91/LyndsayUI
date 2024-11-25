#include "Event/ThreadEventManager.h"

#include <memory>

#include "Event/IEventData.h"

using namespace LyndsayUI;

//  Declare functions here
void ThreadEventManager::ProcessEvents() {
    std::unique_ptr<IEventData> event;
    while ((event = eventQueue->PollEventData())) {
        // Deal with the event
    }
}

void ThreadEventManager::PushEvent(std::unique_ptr<IEventData> event) {

}
