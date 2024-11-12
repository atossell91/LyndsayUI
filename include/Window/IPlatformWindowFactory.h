#pragma once

#include <memory>

#include "Window/IWindow.h"

namespace LyndsayUI {
    class IPlatformWindowFactory {
    public:
        virtual ~IPlatformWindowFactory() {}
        //  Public stuff here
        virtual std::unique_ptr<IWindow> CreateWindow() = 0;
    };
} // LyndsayUI
