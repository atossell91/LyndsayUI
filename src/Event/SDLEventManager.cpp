#include "Event/SDLEventManager.h"

#include <SDL3/SDL.h>
#include <functional>

#include "Event/EventTypes.h"
#include "Event/EventSpace.h"
#include "Utils.h"

#include <iostream>

using namespace RebeccaUI;

//  Declare functions here
void RebeccaUI::SDLEventManager::ProcessEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        HandleEvent(event);
    }
}

void SDLEventManager::HandleEvent(SDL_Event& event) {
    switch (event.type)
    {
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED: {
            
            //  If this causes a problem, try using std::move
            //    Though ChatGPT suggested that the factory returns an r-value
            //    which allows it to be moved without callning std::move
            auto evt = Utils::CastUniquePtr<IEvent, CloseButtonPressedEvent>(
                eventFactory->createEvent(EventTypes::CLOSE_BUTTON_PRESSED_EVENT)
            );
            
            evt->SetWindowID(windowResolver->ResolveIndex(event.window.windowID));
            
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
