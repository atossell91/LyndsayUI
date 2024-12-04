#pragma once

#include <SDL3/SDL.h>

#include <list>
#include <functional>
#include <memory>

#include "Event/IQueuedEventData.h"
#include "Event/IEventManager.h"
#include "Event/Event.h"
#include "Event/EventData/WindowCloseButtonClickedEventData.h"

namespace NSLyndsayUI {
    class SDLEventManager : public IEventManager {
    private:
        void handleEvent(SDL_Event&);
    public:
        //  Public stuff here
        Event<WindowCloseButtonClickedEventData> WindowCloseButtonClickedEvent;

        void ProcessEvents();
        void PushEvent(std::unique_ptr<IQueuedEventData> event);

        SDLEventManager() {}
    };
} // LyndsayUI
