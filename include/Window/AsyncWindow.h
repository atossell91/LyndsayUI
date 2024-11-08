#pragma once

#include <memory>
#include <thread>

#include "Window/WindowFactory.h"

namespace RebeccaUI {
    class AsyncWindow : public IWindow {
    private:
        //  Private stuff here

        //  Event disptcher
        //  Event queue
        //  Event poller
        std::unique_ptr<std::thread> windowThread;
        std::unique_ptr<IWindow> platformWindow;

        bool isRunning = true;
        time_t sleepDelay = 20;
        int windowId;

        //  Runs in the thread
        void windowLoop();
        void threadMain();
        AsyncWindow(int id, std::unique_ptr<IWindow> window) : windowId {id}, platformWindow{std::move(window)} {}

        friend std::unique_ptr<IWindow> WindowFactory::CreateAsynchronousWindow();
    public:
        //  Public stuff here
        ~AsyncWindow();
    };
} // RebeccaUI
