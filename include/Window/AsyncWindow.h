#pragma once

#include <memory>
#include <thread>

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

        //  Runs in the thread
        void windowLoop();
        void threadMain();
    public:
        //  Public stuff here
        AsyncWindow();
        ~AsyncWindow();
    };
} // RebeccaUI
