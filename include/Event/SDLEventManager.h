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
        int drawEventCode = 0;

        static constexpr int kPollLimit = 100;
        void handleEvent(SDL_Event&);
        void (NSLyndsayUI::SDLEventManager::*eventFunc)();
        void grabEvents();
        void waitForEvents();
        void initEvents();
    public:
        //  Public stuff here
        void PollAndProcessEvents();
        void WaitAndProcessEvents();
        void PushEvent(std::unique_ptr<IQueuedEventData> event);
        void SetEventMode(EventMode mode) { eventFunc = &SDLEventManager::grabEvents; }

        SDLEventManager() { initEvents(); }

        int GetDrawEventCode() const { return drawEventCode; }
    };
} // LyndsayUI
