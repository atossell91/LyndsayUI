#pragma once

#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>

#include "Event/IEventQueue.h"
#include "Event/IWindowEventCoordinator.h"
#include "Window/WindowBase.h"
#include "Window/IAsyncWindow.h"

#include "Window/WindowFactory.h"

namespace NSLyndsayUI {
    class AsyncWindow : public WindowBase, public IAsyncWindow {
    private:
        //  Private stuff here

        std::unique_ptr<IWindow> platformWindow;

        std::unique_ptr<IWindowEventCoordinator> eventProcessor;

        std::mutex mutex;
        std::condition_variable conditionVariable;

        std::unique_ptr<std::thread> windowThread;

        std::atomic<bool> isRunning{true};
        time_t sleepDelay = 20;
        int windowId;
        std::thread::id workerThreadId;

        bool isWorkerThread() { return std::this_thread::get_id() == workerThreadId; }

        //  Runs in the thread
        void windowLoop();
        AsyncWindow(int id, std::unique_ptr<IWindowEventCoordinator> eventProc) :
            WindowBase(id), eventProcessor{std::move(eventProc)} {}

        friend std::unique_ptr<IWindow> WindowFactory::CreateAsynchronousWindow();
        friend void WindowFactory::CreateWindowThread(AsyncWindow* window, std::unique_ptr<IWindow>& innerWin, bool& isWinset, std::thread::id& workerThreadId);
    public:
        //  Public stuff here
        ~AsyncWindow();
        std::mutex& GetMutex() { return mutex; }
        std::condition_variable& GetConditionVariable() { return conditionVariable; }
        void Close();
    };
} // LyndsayUI
