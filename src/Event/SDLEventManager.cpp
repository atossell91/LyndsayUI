#include "Event/SDLEventManager.h"

#include <SDL3/SDL.h>
#include <functional>

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
    case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
        // Event
        break;
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
    
    default:
        break;
    }
}
