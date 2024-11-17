#pragma once

#include <memory>

#include "Event/IEventManager.h"

namespace LyndsayUI {
    class IEventManagerFactory {
    public:
        virtual ~IEventManagerFactory() {}
        //  Public stuff here
        virtual std::unique_ptr<IEventManagerFactory> CreateEventManager() = 0;
    };
} // build
