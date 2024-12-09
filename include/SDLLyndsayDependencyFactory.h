#pragma once

#include <memory>

#include "ILyndsayDependencyFactory.h"
#include "Window/IWindowManager.h"
#include "Event/IWindowEventCoordinator.h"
#include "Window/IWindowFactory.h"
#include "Window/CustomWindowFactory.h"
#include "SammieCollection.h"

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

        std::unique_ptr<IWindowCollection<ImmediateWindow>> GetImmediateWindowCollection() { return std::make_unique<SammieCollection<ImmediateWindow>>(); }
        std::unique_ptr<IWindowCollection<RetainedWindow>> GetRetainedWindowCollection() { return std::make_unique<SammieCollection<RetainedWindow>>(); }
    };
} // LyndsayUI
