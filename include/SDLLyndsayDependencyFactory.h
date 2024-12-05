#pragma once

#include <memory>

#include "ILyndsayDependencyFactory.h"
#include "Window/IWindowManager.h"
#include "Event/IEventProcessor.h"
#include "Window/IWindowFactory.h"

namespace NSLyndsayUI {
    class SDLLyndsayDependencyFactory : public ILyndsayDependencyFactory {
    private:
        //  Private stuff here
        void setupEvents();
        void build();

        std::unique_ptr<IWindowManager> windowManager;
        std::unique_ptr<IEventProcessor> eventProcessor;
    public:
        //  Public stuff here
        SDLLyndsayDependencyFactory() { build(); }
        std::unique_ptr<IWindowManager> GetWindowManager() { return std::move(windowManager);}
        std::unique_ptr<IEventProcessor> GetEventProcessor() { return std::move(eventProcessor);}
        std::unique_ptr<IWindowFactory> GetWindowFactory();
    };
} // LyndsayUI
