#pragma once

#include "Event/EventDataBase.h"

#include <memory>
#include <SDL3/SDL.h>

namespace SDLEventAdaptor {
// Populate the namespace here
    SDL_Event LyndsayToSDLEvent(std::unique_ptr<IEventData> data) {

    }
} // SDLEventAdaptor
