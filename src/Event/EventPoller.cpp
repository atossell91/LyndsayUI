#include "Event/EventPoller.h"

#include <memory>

#include "Event/IEvent.h"

using namespace RebeccaUI;

//  Declare functions here
void EventPoller::PollEvents() {
    std::unique_ptr<IEvent> ev;
    while (eventQueue && (ev = eventQueue->GetEvent())) {
        if (eventTent) {
            eventTent->RecieveEvent(std::move(ev));
        }
    }
}
