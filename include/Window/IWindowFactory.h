#pragma once

#include <memory>

#include "IWindow.h"

namespace NSLyndsayUI {
    class IWindowFactory {
    public:
        virtual ~IWindowFactory() {}
        //  Public stuff here
        virtual std::unique_ptr<IWindow> CreateSynchronousWindow() = 0;
        virtual std::unique_ptr<IWindow> CreateAsynchronousWindow() = 0;
    };
} // LyndsayUI
