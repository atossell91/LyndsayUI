#pragma once

#include "Window/IWindow.h"
#include "IPlatformWindowFactory.h"

namespace NSLyndsayUI {
    class SDLWindowFactory : public IPlatformWindowFactory {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        std::unique_ptr<IWindow> CreateWindow();
    };
} // LyndsayUI
