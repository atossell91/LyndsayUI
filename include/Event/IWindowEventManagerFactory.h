#pragma once

#include "Event/AbstractWindowEventManager.h"

#include <memory>

namespace NSLyndsayUI {
    class IWindowEventManagerFactory {
    public:
        virtual ~IWindowEventManagerFactory() {}
        //  Public stuff here
        virtual std::unique_ptr<AbstractWindowEventManager> CreateEventManager() = 0;
    };
} // LyndsayUI
