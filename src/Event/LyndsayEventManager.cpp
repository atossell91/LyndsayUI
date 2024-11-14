#include "Event/LyndsayEventManager.h"

using namespace LyndsayUI;

//  Declare functions here
void LyndsayEventManager::ProcessEvents() {
    std::unique_ptr<IEvent> event;
    while ((event = eventGetter->GetQueuedEvent())) {
        eventTent->RecieveEvent(std::move(event));
    }
}
