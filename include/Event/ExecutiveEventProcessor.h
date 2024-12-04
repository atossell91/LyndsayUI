#pragma once

#include <vector>
#include <memory>

#include "IEventManager.h"
#include "Event/IEventProcessor.h"

namespace NSLyndsayUI {
    class ExecutiveEventProcessor : public IEventProcessor {
    private:
        //  Private stuff here
        std::unique_ptr<IEventManager> platformEventManager;
        std::unique_ptr<IEventManager> threadEventManager;
    public:
        //  Public stuff here
        ExecutiveEventProcessor(std::unique_ptr<IEventManager> threadEvManager, std::unique_ptr<IEventManager> platformEvManager) : 
            threadEventManager{std::move(threadEvManager)}, platformEventManager{std::move(platformEvManager)} {}
        void ProcessEvents() { 
            threadEventManager->ProcessEvents();
            platformEventManager->ProcessEvents();
         }
    };
} // LyndsayUI
