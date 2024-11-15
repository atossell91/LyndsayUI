#include "Event/SDLEventManager.h"

#include <SDL3/SDL.h>
#include <functional>

#include "Event/EventTypes.h"
#include "Event/EventSpace.h"
#include "Utils.h"

#include <iostream>

using namespace LyndsayUI;

//  Declare functions here
void LyndsayUI::SDLEventManager::ProcessEvents() {
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

            auto oldEv = eventFactory->createEvent(EventTypes::CLOSE_BUTTON_PRESSED_EVENT);
            auto evt = Utils::CastUniquePtr<IEvent, CloseButtonPressedEvent>(std::move(oldEv));
            
            evt->SetWindowID(windowResolver->ResolveIndex(event.window.windowID));

            if (receiver) {
                receiver->RecieveEvent(std::move(evt));
            }
            else {
                std::cout << "Receiver is nullptr" << std::endl;
            }

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
