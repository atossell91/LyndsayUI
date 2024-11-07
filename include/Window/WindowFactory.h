#pragma once

#include "Window/IWindowFactory.h"

#include <memory>

#include "Window/IWindow.h"

namespace RebeccaUI {
    class WindowFactory : public IWindowFactory{
    private:
        //  Private stuff here
        int nextWindowId = 0;
        int generateWindowId() { return nextWindowId++; }
    public:
        //  Public stuff here
        std::unique_ptr<IWindow> CreateSynchronousWindow();
        std::unique_ptr<IWindow> CreateAsynchronousWindow();
    };
} // RebeccaUI
