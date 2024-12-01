#pragma once

#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Event/IEventQueue.h"
#include "Event/IEventProcessor.h"
#include "Window/WindowBase.h"
#include "Window/IAsyncWindow.h"

#include "Window/WindowFactory.h"

namespace LyndsayUI {
    class AsyncWindow : public WindowBase, public IAsyncWindow {
    private:
        //  Private stuff here

        std::unique_ptr<IWindow> platformWindow;

        std::unique_ptr<IEventProcessor> eventProcessor;

        std::mutex mutex;
        std::condition_variable conditionVariable;

        std::unique_ptr<std::thread> windowThread;

        bool isRunning = true;
        time_t sleepDelay = 20;
        int windowId;

        //  Runs in the thread
        void windowLoop();
        AsyncWindow(int id, std::unique_ptr<IEventProcessor> eventProc) :
            WindowBase(id), eventProcessor{std::move(eventProc)} {}

        friend std::unique_ptr<IWindow> WindowFactory::CreateAsynchronousWindow();
        friend std::unique_ptr<std::thread> WindowFactory::CreateWindowThread(AsyncWindow* window, std::unique_ptr<IWindow>& innerWin, bool& isWinset);
    public:
        //  Public stuff here
        ~AsyncWindow();
        std::mutex& GetMutex() { return mutex; }
        std::condition_variable& GetConditionVariable() { return conditionVariable; }
        void Close();
    };
} // LyndsayUI
