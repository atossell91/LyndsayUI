#include "Window/WindowFactory.h"

#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

#include "Event/IEventTent.h"
#include "Event/EventTent.h"
#include "Event/EventQueue.h"
#include "Event/EventPoller.h"

#include "Window/IWindow.h"
#include "Window/IAsyncWindow.h"
#include "Window/AsyncWindow.h"
#include "Window/SyncWindow.h"
#include "Promise.h"

using namespace RebeccaUI;

std::unique_ptr<IWindow> WindowFactory::CreateSynchronousWindow() {
    auto platWindow = platformWinFactory->CreateWindow();
    auto winEvTent = std::make_unique<EventTent>();
    int newWinId = generateWindowId();
    int platWinId = platWindow->GetWindowId();
    // Put these IDs into the resolver
    resolver->MapIndices(platWinId, newWinId);
    auto window = std::unique_ptr<SyncWindow>( new SyncWindow(newWinId, std::move(winEvTent)) );
    window->platformWindow = std::move(platWindow);

    return window;
}

std::unique_ptr<IWindow> WindowFactory::CreateAsynchronousWindow() {
    auto winEvTent = std::make_unique<EventTent>();
    auto winQueue = std::make_unique<EventQueue>();
    auto winPoller = std::make_unique<EventPoller>(winEvTent.get(), winQueue.get());
    int newWinId = generateWindowId();
    auto window = std::unique_ptr<AsyncWindow>( new AsyncWindow(newWinId, std::move(winEvTent), std::move(winQueue), std::move(winPoller)) );

    std::unique_ptr<IWindow> innerwin;

    bool isWinset = false;
    std::unique_lock<std::mutex> lock(window->GetMutex(), std::defer_lock);

    //  Start the thread, and get a pointer to it. The SDLWindow can be setup in here
    //auto thread = std::make_unique<std::thread>(CreateWindowThread, window.get(), innerwin, isWinset);
    auto thread = std::make_unique<std::thread>(
        &WindowFactory::CreateWindowThread, this, window.get(), std::ref(innerwin), std::ref(isWinset)
    );

    window->GetConditionVariable().wait(lock, [isWinset](){ return isWinset; });
    int platWinId = innerwin->GetWindowId();
    resolver->MapIndices(platWinId, newWinId);

    window->platformWindow = std::move(innerwin);
    window->windowThread = std::move(thread);

    return window;
}

// Runs in the new thread (i.e not on the main thread - be careful)
std::unique_ptr<std::thread> WindowFactory::CreateWindowThread(AsyncWindow* window, std::unique_ptr<IWindow>& innerWin, bool& isWinset) {
        // Creation behaviour
        std::unique_lock<std::mutex> lock(window->GetMutex());
        innerWin = platformWinFactory->CreateWindow();
        isWinset = true;
        lock.unlock();
        window->GetConditionVariable().notify_all();

        // Window loop behaviour
        while (true) {
            window->threadMain();
            ////  I'd like to do this, but this lambda doesn't have access to these functions/variables
            //window->PollEvents();
            //std::this_thread::sleep_for(std::chrono::milliseconds(window->sleepDelay));
        }

        // Cleanup behaviour
}
