#pragma once

#include <memory>

#include "Window/IWindowManager.h"
#include "Event/IWindowEventCoordinator.h"
#include "Window/IWindowFactory.h"
#include "Window/CustomWindowFactory.h"
#include "Window/IWindowCollection.h"
#include "Window/ImmediateWindow.h"
#include "Window/RetainedWindow.h"

namespace NSLyndsayUI {
    class ILyndsayDependencyFactory {
    public:
        virtual ~ILyndsayDependencyFactory() {}
        //  Public stuff here
        virtual std::unique_ptr<IWindowManager> GetWindowManager() = 0;
        virtual std::unique_ptr<IWindowEventCoordinator> GetEventProcessor() = 0;
        virtual std::unique_ptr<CustomWindowFactory> GetCustomWindowFactory() = 0;

        virtual std::unique_ptr<IWindowCollection<ImmediateWindow>> GetImmediateWindowCollection() = 0;
        virtual std::unique_ptr<IWindowCollection<RetainedWindow>> GetRetainedWindowCollection() = 0;
    };
} // LyndsayUI
