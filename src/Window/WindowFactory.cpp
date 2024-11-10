#include "Window/WindowFactory.h"

#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Event/IEventTent.h"
#include "Event/EventTent.h"
#include "Event/EventQueue.h"
#include "Event/EventPoller.h"

#include "Window/IWindow.h"
#include "Window/AsyncWindow.h"
#include "Window/SyncWindow.h"
#include "Promise.h"

using namespace RebeccaUI;

//  Declare functions here
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

//  SDLWindow's constructor (i.e the factory method that uses it) needs to be called inside the new thread
//    for the glContext to work properly.
//  That mostly applies to the SDLWindow stuff though. The AsyncWindow object can exist wherever the hell it
//    likes, so long as the thread can access it's data. Actually, it makes sense for it to be declared outside
//    the thread, since it's the program's main way of interacting with the async window.
std::unique_ptr<IWindow> WindowFactory::CreateAsynchronousWindow() {
    //  Might want to modify the asyncWindow to take a thread instead? Or can I declare the platWindow outside
    //    the thread, initialize it in the thread and then pass this in? But AsyncWindow still needs a thread
    //    regardless.
    //  That said, AsyncWindow will also need a pointer to the platformWindow too. It needs both.
    auto winEvTent = std::make_unique<EventTent>();
    auto winQueue = std::make_unique<EventQueue>();
    auto winPoller = std::make_unique<EventPoller>(winEvTent.get(), winQueue.get());
    int newWinId = generateWindowId();
    auto window = std::unique_ptr<AsyncWindow>( new AsyncWindow(newWinId, std::move(winEvTent), std::move(winQueue), std::move(winPoller)) );

    std::unique_ptr<IWindow> innerwin;

    bool isWinset = false;
    std::unique_lock<std::mutex> lock(window->GetMutex(), std::defer_lock);

    //  Start the thread, and get a pointer to it. The SDLWindow can be setup in here
    auto thread = std::make_unique<std::thread>(
        [this, &window, &innerwin, &isWinset](){
            // Creation behaviour
            std::unique_lock<std::mutex> lock(window->GetMutex());
            innerwin = platformWinFactory->CreateWindow();
            isWinset = true;
            lock.unlock();
            window->GetConditionVariable().notify_all();
            // Window loop behaviour
            // Cleanup behaviour
        }
    );

    window->GetConditionVariable().wait(lock, [isWinset](){ return isWinset; });
    int platWinId = innerwin->GetWindowId();
    // put newWinId and platWinId into a resolver
    resolver->MapIndices(platWinId, newWinId);

    window->platformWindow = std::move(innerwin);
    window->windowThread = std::move(thread);

    return window;
}
