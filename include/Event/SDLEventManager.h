#pragma once

#include <SDL3/SDL.h>

#include <list>
#include <functional>
#include <memory>

#include "Event/IQueuedEventData.h"
#include "Event/AbstractWindowEventManager.h"
#include "Event/Event.h"    

namespace NSLyndsayUI {
    class SDLEventManager : public AbstractWindowEventManager {
    private:
        void handleEvent(SDL_Event&);
    public:
        //  Public stuff here

        void ProcessEvents();
        void PushEvent(std::unique_ptr<IQueuedEventData> event);

        SDLEventManager() {}
    };
} // LyndsayUI
