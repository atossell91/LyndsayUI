#pragma once

#include <memory>

#include "Window/IWindowManager.h"
#include "Event/IEventProcessor.h"
#include "Window/IWindowFactory.h"

namespace NSLyndsayUI {
    class ILyndsayDependencyFactory {
    public:
        virtual ~ILyndsayDependencyFactory() {}
        //  Public stuff here
        virtual std::unique_ptr<IWindowManager> GetWindowManager() = 0;
        virtual std::unique_ptr<IEventProcessor> GetEventProcessor() = 0;
        virtual std::unique_ptr<IWindowFactory> GetWindowFactory() = 0;
    };
} // LyndsayUI
