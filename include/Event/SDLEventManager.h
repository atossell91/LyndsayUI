#pragma once

#include <SDL3/SDL.h>

#include <list>
#include <functional>
#include <memory>

#include "Event/IEventData.h"
#include "Event/IEventManager.h"

#include "Event/EventTypes/WindowCloseButtonClicked.h"

namespace LyndsayUI {
    class SDLEventManager : public IEventManager {
    private:
        void handleEvent(SDL_Event&);
    public:
        //  Public stuff here
        WindowCloseButtonClicked WindowClosed;

        void ProcessEvents();
        void PushEvent(std::unique_ptr<IEventData> event);

        SDLEventManager() {}
    };
} // LyndsayUI
