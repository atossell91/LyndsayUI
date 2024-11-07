#pragma once

#include <memory>

#include "IWindow.h"

namespace RebeccaUI {
    class IWindowFactory {
    public:
        virtual ~IWindowFactory() {}
        //  Public stuff here
        virtual std::unique_ptr<IWindow> CreateSynchronousWindow() = 0;
        virtual std::unique_ptr<IWindow> CreateAsynchronousWindow() = 0;
    };
} // RebeccaUI
