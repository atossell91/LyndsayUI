#pragma once

#include <memory>

#include "Event/IWindowEventManagerFactory.h"
#include "Event/SDLEventManager.h"

namespace NSLyndsayUI {
    class SDLWindowEventManagerFactory : public IWindowEventManagerFactory {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        std::unique_ptr<AbstractWindowEventManager> CreateEventManager();
    };
} // LyndsayUI
