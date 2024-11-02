#include "Event/SDLEventManager.h"

#include <SDL3/SDL.h>
#include <functional>

#include "Event/EventTypes.h"
#include "Event/EventSpace.h"

#include <iostream>

using namespace RixinSDL;

//  Declare functions here
void RixinSDL::SDLEventManager::ProcessEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        HandleEvent(event);
    }
}

void SDLEventManager::HandleEvent(SDL_Event& event) {
    switch (event.type)
    {
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED: {
            // Event
            std::unique_ptr<IEvent> evt = eventFactory->createEvent(EventTypes::CLOSE_BUTTON_PRESSED_EVENT);

            //  Cast the IEvent unique_ptr to a CloseButtonPressedEvent unique_ptr
            IEvent* eventPtr = evt.get();
            CloseButtonPressedEvent* cEvtPtr = static_cast<CloseButtonPressedEvent*>(eventPtr);
            std::unique_ptr<CloseButtonPressedEvent> jos = std::unique_ptr<CloseButtonPressedEvent>(cEvtPtr);
            evt.release();
            
            eventRouter->RouteEvent(std::move(evt));
            break;
        }
        case SDL_EVENT_KEY_DOWN:
            // Event
            break;

        case SDL_EVENT_KEY_UP:
            // Event
            break;

        case SDL_EVENT_MOUSE_MOTION:
            // Event
            break;

        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            // Event
            break;

        case SDL_EVENT_MOUSE_BUTTON_UP:
            // Event
            break;

        case SDL_EVENT_QUIT:
            // Event
            break;
    }
}
