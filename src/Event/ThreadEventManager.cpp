#include "Event/ThreadEventManager.h"

using namespace LyndsayUI;

//  Declare functions here
void ThreadEventManager::ProcessEvents() {
    std::unique_ptr<IEvent> event;
    while ((event = eventGetter->GetQueuedEvent())) {
        eventTent->RecieveEvent(std::move(event));
    }
}
