#pragma once

#include <memory>

#include "ILyndsayDependencyFactory.h"
#include "Window/IWindowManager.h"
#include "Event/IWindowEventCoordinator.h"
#include "Window/IWindowFactory.h"
#include "Window/CustomWindowFactory.h"
#include "Window/CustomWindow.h"
#include "WindowCollection.h"

namespace NSLyndsayUI {
    class SDLLyndsayDependencyFactory : public ILyndsayDependencyFactory {
    private:
        //  Private stuff here
        void setupEvents();
        void build();

        std::unique_ptr<IWindowManager> windowManager;
        std::unique_ptr<IWindowEventCoordinator> eventProcessor;
    public:
        //  Public stuff here
        SDLLyndsayDependencyFactory() { build(); }
        std::unique_ptr<IWindowManager> GetWindowManager() { return std::move(windowManager);}
        std::unique_ptr<IWindowEventCoordinator> GetEventProcessor() { return std::move(eventProcessor);}
        std::unique_ptr<IWindowFactory> GetWindowFactory();
        std::unique_ptr<CustomWindowFactory> GetCustomWindowFactory();

        std::unique_ptr<IWindowCollection<CustomWindow>> GetWindowCollection() { return std::make_unique<WindowCollection<CustomWindow>>(); }
        std::unique_ptr<IWindowCollection<CustomWindow>> GetRetainedWindowCollection() { return std::make_unique<WindowCollection<CustomWindow>>(); }
    };
} // LyndsayUI
