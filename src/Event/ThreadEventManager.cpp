#include "Event/ThreadEventManager.h"

#include <memory>

#include "Event/IQueuedEventData.h"

using namespace NSLyndsayUI;

//  Declare functions here
void ThreadEventManager::ProcessEvents() {
    std::unique_ptr<IQueuedEventData> event;
    while ((event = eventQueue->PollEventData())) {
        // Deal with the event
    }
}

void ThreadEventManager::PushEvent(std::unique_ptr<IQueuedEventData> event) {

}
