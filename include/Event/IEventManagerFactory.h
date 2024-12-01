#pragma once

#include "Event/IEventManager.h"

#include <memory>

namespace LyndsayUI {
    class IEventManagerFactory {
    public:
        virtual ~IEventManagerFactory() {}
        //  Public stuff here
        virtual std::unique_ptr<IEventManager> CreateEventManager() = 0;
    };
} // LyndsayUI
