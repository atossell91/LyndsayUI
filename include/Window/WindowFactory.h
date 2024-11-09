#pragma once

#include <memory>
#include <mutex>
#include <condition_variable>

#include "Window/IPlatformWindowFactory.h"
#include "Window/IWindowFactory.h"
#include "Window/IWindow.h"

namespace RebeccaUI {
    class WindowFactory : public IWindowFactory{
    private:
        //  Private stuff here
        int nextWindowId = 0;
        std::unique_ptr<IPlatformWindowFactory> platformWinFactory;
        int generateWindowId() { return nextWindowId++; }
    public:
        //  Public stuff here
        WindowFactory(std::unique_ptr<IPlatformWindowFactory> factory) : platformWinFactory{std::move(factory)} {}
        std::unique_ptr<IWindow> CreateSynchronousWindow();
        std::unique_ptr<IWindow> CreateAsynchronousWindow();
    };
} // RebeccaUI
