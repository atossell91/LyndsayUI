#pragma once

#include "ILyndsayDependencyFactory.h"

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
