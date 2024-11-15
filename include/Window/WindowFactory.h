#pragma once

#include <memory>
#include <mutex>
#include <condition_variable>
#include <thread>

#include "IMappableIndexResolver.h"

#include "Window/IPlatformWindowFactory.h"
#include "Window/IWindowFactory.h"
#include "Window/IAsyncWindow.h"
#include "Window/IWindow.h"

namespace LyndsayUI {

    class AsyncWindow;

    class WindowFactory : public IWindowFactory {
    private:
        //  Private stuff here
        int nextWindowId = 0;
        std::unique_ptr<IPlatformWindowFactory> platformWinFactory;
        std::shared_ptr<IMappableIndexResolver> resolver;
        int generateWindowId() { return nextWindowId++; }
    public:
        //  Public stuff here
        WindowFactory(std::unique_ptr<IPlatformWindowFactory> factory, std::shared_ptr<IMappableIndexResolver> winResolver) : 
            platformWinFactory{std::move(factory)},  resolver{winResolver} {}
        std::unique_ptr<IWindow> CreateSynchronousWindow();
        std::unique_ptr<IWindow> CreateAsynchronousWindow();
        std::unique_ptr<std::thread> CreateWindowThread(AsyncWindow* window, std::unique_ptr<IWindow>& innerWin, bool& isWinset);
    };
} // LyndsayUI
