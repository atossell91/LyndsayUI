#pragma once

#include <vector>
#include <memory>

#include "IEventManager.h"
#include "Event/IWindowEventCoordinator.h"
#include "Event/AbstractWindowEventManager.h"

namespace NSLyndsayUI {
    class WindowEventCoordinator : public IWindowEventCoordinator {
    private:
        //  Private stuff here
        std::unique_ptr<AbstractWindowEventManager> platformEventManager;
        std::unique_ptr<IEventManager> threadEventManager;
    public:
        //  Public stuff here
        WindowEventCoordinator(std::unique_ptr<IEventManager> threadEvManager, std::unique_ptr<AbstractWindowEventManager> platformEvManager) : 
            threadEventManager{std::move(threadEvManager)}, platformEventManager{std::move(platformEvManager)} {}
        void ProcessEvents() { 
            threadEventManager->ProcessEvents();
            platformEventManager->ProcessEvents();
         }
        IEventManager* GetThreadEventManager() { return threadEventManager.get(); }
        AbstractWindowEventManager* GetPlatformEventManager() { return platformEventManager.get(); }
    };
} // LyndsayUI
