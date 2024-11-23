#pragma once

#include <memory>

#include "ILyndsayDependencyFactory.h"
#include "Event/IEventTent.h"
#include "Window/IWindowManager.h"

namespace LyndsayUI {
    class SDLLyndsayDependencyFactory : public ILyndsayDependencyFactory {
    private:
        //  Private stuff here
        std::weak_ptr<IEventTent> mainEventTent;

        std::shared_ptr<IEventTent> createMainEventTent();
        void registerEvents(IWindowManager* winMgr);
    public:
        //  Public stuff here
        std::unique_ptr<IWindowManager> CreateWindowManager();
        std::unique_ptr<IEventProcessor> CreateEventProcessor();
    };
} // LyndsayUI
