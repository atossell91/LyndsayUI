#pragma once

#include <memory>
#include <thread>

#include "Window/WindowBase.h"
#include "Window/WindowFactory.h"

namespace RebeccaUI {
    class AsyncWindow : public WindowBase {
    private:
        //  Private stuff here

        //  Event disptcher
        //  Event queue
        //  Event poller
        std::unique_ptr<std::thread> windowThread;
        std::unique_ptr<IWindow> platformWindow;

        std::mutex mutex;
        std::condition_variable conditionVariable;

        bool isRunning = true;
        time_t sleepDelay = 20;
        int windowId;

        //  Runs in the thread
        void windowLoop();
        void threadMain();
        AsyncWindow(int id, std::unique_ptr<IEventTent> evTent) : WindowBase(id, std::move(evTent)) {}

        friend std::unique_ptr<IWindow> WindowFactory::CreateAsynchronousWindow();
    public:
        //  Public stuff here
        ~AsyncWindow();
        std::mutex& GetMutex() { return mutex; }
        std::condition_variable& GetConditionVariable() { return conditionVariable; }
    };
} // RebeccaUI
