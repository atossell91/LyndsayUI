#pragma once

#include <memory>

#include "ILyndsayDependencyFactory.h"
#include "Window/IWindowManager.h"

namespace LyndsayUI {
    class SDLLyndsayDependencyFactory : public ILyndsayDependencyFactory {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        std::unique_ptr<IWindowManager> CreateWindowManager();
        std::unique_ptr<IEventProcessor> CreateEventProcessor();
    };
} // LyndsayUI
