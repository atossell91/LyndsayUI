#include "Event/SDLQueuedEventGetter.h"

#include <SDL3/SDL.h>
#include <memory>

#include "Event/IEvent.h"
#include "Event/EventFactory.h"
#include "Event/EventSpace.h"
#include "Utils.h"

using namespace LyndsayUI;

//  Declare functions here
std::unique_ptr<IEvent> SDLQueuedEventGetter::GetQueuedEvent() {
    SDL_Event sdlEvent;
    SDL_PollEvent(&sdlEvent);

    switch (sdlEvent.type)
    {
    case SDL_EVENT_QUIT:
    {
        // Create a CloseButtonPressedEvent & return it

        auto oldEv = eventFactory->createEvent(EventTypes::CLOSE_BUTTON_PRESSED_EVENT);
        auto evt = Utils::CastUniquePtr<IEvent, CloseButtonPressedEvent>(std::move(oldEv));

        return std::move(evt);
    }
    default:
        return nullptr;
    }
}
