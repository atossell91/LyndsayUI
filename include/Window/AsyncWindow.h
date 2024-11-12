#pragma once

#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Event/IEventQueue.h"
#include "Event/IEventPoller.h"
#include "Window/WindowBase.h"
#include "Window/IAsyncWindow.h"

#include "Window/WindowFactory.h"

namespace LyndsayUI {
    class AsyncWindow : public WindowBase, public IAsyncWindow {
    private:
        //  Private stuff here

        //  Event disptcher
        std::unique_ptr<IEventQueue> eventQueue;
        std::unique_ptr<IEventPoller> eventPoller;
        std::unique_ptr<std::thread> windowThread;
        std::unique_ptr<IWindow> platformWindow;

        std::mutex mutex;
        std::condition_variable conditionVariable;

        bool isRunning = true;
        time_t sleepDelay = 20;
        int windowId;

        //  Runs in the thread
        void windowLoop();
        AsyncWindow(int id, std::unique_ptr<IEventTent> evTent,
            std::unique_ptr<IEventQueue> queue, std::unique_ptr<IEventPoller> poller) :
            WindowBase(id, std::move(evTent)), eventQueue{std::move(queue)}, eventPoller{std::move(poller)} {}

        friend std::unique_ptr<IWindow> WindowFactory::CreateAsynchronousWindow();
        friend std::unique_ptr<std::thread> WindowFactory::CreateWindowThread(AsyncWindow* window, std::unique_ptr<IWindow>& innerWin, bool& isWinset);
    public:
        //  Public stuff here
        ~AsyncWindow();
        std::mutex& GetMutex() { return mutex; }
        std::condition_variable& GetConditionVariable() { return conditionVariable; }
    };
} // LyndsayUI
