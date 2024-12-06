#include "Window/WindowFactory.h"

#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <iostream>

#include "Event/EventQueue.h"
#include "Event/ThreadEventManager.h"
#include "Event/WindowEventCoordinator.h"

#include "Window/IWindow.h"
#include "Window/IAsyncWindow.h"
#include "Window/AsyncWindow.h"
#include "Window/SyncWindow.h"
#include "Promise.h"

using namespace NSLyndsayUI;

std::unique_ptr<IWindow> WindowFactory::CreateSynchronousWindow() {
    auto platWindow = platformWinFactory->CreateWindow();
    int platWinId = platWindow->GetWindowId();
    auto window = std::unique_ptr<SyncWindow>( new SyncWindow(platWinId) );
    window->platformWindow = std::move(platWindow);

    return window;
}

std::unique_ptr<IWindow> WindowFactory::CreateAsynchronousWindow() {
    auto winQueue = std::make_unique<EventQueue>();
    auto trMgr = std::make_unique<ThreadEventManager>(std::move(winQueue));
    auto evMgr = WindowEventManagerFactory->CreateEventManager();

    auto exProc = std::make_unique<WindowEventCoordinator>(
        std::move(trMgr),
        std::move(evMgr)
    );
    
    auto window = std::unique_ptr<AsyncWindow>( new AsyncWindow(0, std::move(exProc)) );

    std::unique_ptr<IWindow> innerwin;

    bool isWinset = false;
    std::unique_lock<std::mutex> lock(window->GetMutex(), std::defer_lock);

    //  Start the thread, and get a pointer to it. The SDLWindow can be setup in here
    //auto thread = std::make_unique<std::thread>(CreateWindowThread, window.get(), innerwin, isWinset);
    auto thread = std::make_unique<std::thread>(
        &WindowFactory::CreateWindowThread, this, window.get(), std::ref(innerwin), std::ref(isWinset)
    );

    window->GetConditionVariable().wait(lock, [&isWinset](){ return isWinset; });
    int platWinId = innerwin->GetWindowId();

    window->windowId = platWinId;

    window->platformWindow = std::move(innerwin);
    window->windowThread = std::move(thread);

    window->eventProcessor->GetPlatformEventManager()->WindowCloseButtonClicked.AddEventHandler([win = window.get()](auto data){
        std::cout << "Attempting to close the window!" << std::endl;
        win->Close();
    });
    
    lock.release();

    return window;
}

// Runs in the new thread (i.e not on the main thread - be careful)
void WindowFactory::CreateWindowThread(AsyncWindow* window, std::unique_ptr<IWindow>& innerWin, bool& isWinset) {
        std::cout << "Starting the window thread (" << std::this_thread::get_id() << ")" << std::endl;
        // Creation behaviour
        std::unique_lock<std::mutex> lock(window->GetMutex());
        innerWin = platformWinFactory->CreateWindow();
        isWinset = true;
        lock.unlock();
        window->GetConditionVariable().notify_all();

        // Window loop behaviour
        window->windowLoop();

        // This could probably be replaced with,
        //innerWin.reset(nullptr);
        auto ptr = innerWin.get();
        innerWin.release();
        delete ptr;
}
