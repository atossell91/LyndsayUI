#pragma once

#include <list>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Window/IWindowManager.h"
#include "Window/IWindow.h"
#include "Window/IWindowFactory.h"

#include "Event/IEvent.h"

namespace LyndsayUI
{
    class WindowManager : public IWindowManager {
     private:
        std::list<std::unique_ptr<IWindow>> windows;
        std::unique_ptr<IWindow> singleWindow;
        std::mutex mutex;
        std::condition_variable cv;

        std::unique_ptr<IWindowFactory> factory;

        int currentWindowId = 1;
     public:
        WindowManager(
            std::unique_ptr<IWindowFactory> winFactory) : factory{std::move(winFactory)} {}
            
        void AddSingleWindow(); 
        void AddWindow(const std::string& name, int width, int height);
        void CloseWindow(int windowId);
        IWindow* GetWindow();
        IWindow* GetWindow(int windowId);
        int GetNumWindows() const { return windows.size(); }
        bool IsNoWindows() const;
        void UpdateAll();
    };
} // namespace LyndsayUI
