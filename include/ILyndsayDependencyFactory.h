#pragma once

#include <memory>

#include "Window/IWindowManager.h"
#include "Event/IWindowEventCoordinator.h"
#include "Window/IWindowFactory.h"
#include "Window/CustomWindowFactory.h"
#include "Window/IWindowCollection.h"
#include "Window/CustomWindow.h"

namespace NSLyndsayUI {
    class ILyndsayDependencyFactory {
    public:
        virtual ~ILyndsayDependencyFactory() {}
        //  Public stuff here
        virtual std::unique_ptr<IWindowManager> GetWindowManager() = 0;
        virtual std::unique_ptr<IWindowEventCoordinator> GetEventProcessor() = 0;
        virtual std::unique_ptr<CustomWindowFactory> GetCustomWindowFactory() = 0;

        virtual std::unique_ptr<IWindowCollection<CustomWindow>> GetWindowCollection() = 0;
    };
} // LyndsayUI
