#pragma once

#include "Event/IEventManagerFactory.h"
#include "Event/IEventManager.h"

#include "Event/SDLEventManager.h"
#include "Event/ExecutiveEventProcessor.h"

namespace LyndsayUI {
    class SDLEventManagerFactory : public IEventManagerFactory {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        std::unique_ptr<IEventManagerFactory> CreateEventManager();
    };
} // build
