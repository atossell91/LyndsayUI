#pragma once

#include <memory>

#include "Event/IEventManagerFactory.h"
#include "Event/SDLEventManager.h"

namespace NSLyndsayUI {
    class SDLEventManagerFactory : public IEventManagerFactory {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        std::unique_ptr<IEventManager> CreateEventManager();
    };
} // LyndsayUI
