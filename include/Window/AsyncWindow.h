#pragma once

#include <memory>
#include <thread>

#include "Window/WindowFactory.h"

namespace RebeccaUI {
    class AsyncWindow {
    private:
        //  Private stuff here

        //  Event disptcher
        //  Event queue
        //  Event poller
        std::unique_ptr<std::thread> windowThread;

        bool isRunning = true;
        time_t sleepDelay = 20;
        int windowId;

        //  Runs in the thread
        void windowLoop();
        void threadMain();
        AsyncWindow(int id) : windowId {id} {}

        friend std::unique_ptr<IWindow> WindowFactory::CreateAsynchronousWindow();
    public:
        //  Public stuff here
        ~AsyncWindow();
    };
} // RebeccaUI
