#pragma once

#include <memory>

#include "Window/IWindowManager.h"
#include "Event/IWindowEventCoordinator.h"
#include "Window/IWindowFactory.h"
#include "Window/WindowFactory.h"
#include "Window/IWindowCollection.h"
#include "Window/Window.h"

namespace NSLyndsayUI {
    class ILyndsayDependencyFactory {
    public:
        virtual ~ILyndsayDependencyFactory() {}
        //  Public stuff here
        virtual std::unique_ptr<IWindowManager> GetWindowManager() = 0;
        virtual std::unique_ptr<IWindowEventCoordinator> GetEventProcessor() = 0;
        virtual std::unique_ptr<WindowFactory> GetWindowFactory() = 0;

        virtual std::unique_ptr<IWindowCollection<Window>> GetWindowCollection() = 0;
    };
} // LyndsayUI
