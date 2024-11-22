#include "Event/ThreadEventManager.h"

#include <memory>

#include "Event/IEvent.h"

using namespace LyndsayUI;

//  Declare functions here
void ThreadEventManager::ProcessEvents() {
    std::unique_ptr<IEvent> event;
    while ((event = eventQueue->GetEvent())) {
        eventTent->RecieveEvent(std::move(event));
    }
}

void ThreadEventManager::PushEvent(std::unique_ptr<IEvent> event) {

}
