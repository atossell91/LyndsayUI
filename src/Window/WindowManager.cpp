#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Utils.h"
#include "Window/WindowManager.h"
#include "Window/Window.h"
#include "Window/IWindow.h"
#include "Event/EventSpace.h"
#include "Event/EventTypes.h"

#include <iostream>

std::unique_ptr<RebeccaUI::Window> RebeccaUI::WindowManager::windowFactory() {
    std::unique_ptr<Window> window = std::make_unique<Window>("Rebecca is cute", 1920, 1080);

    //window->GetEventProcessor().addEventHandler(SDL_EVENT_QUIT, [&window](std::unique_ptr<IEvent> d){
    //    std::cout << "Stopping" << std::endl;
    //    window->stopLoop();
    //});

    return std::move(window);
}

void RebeccaUI::WindowManager::AddWindow(const std::string& name, int width, int height) {
    /*
    WindowThread windowThread;

    //  Start the window thread
    std::thread* t = new std::thread([&windowThread, this](const std::string& name, int width, int height){
        Window window(name, width, height);
        {
            std::lock_guard<std::mutex> lg(mutex);
            windowThread.window = &window;
        }

        //window.GetEventProcessor().addEventHandler(91,
        //[](std::unique_ptr<IEvent> event){
        //    std::cout << "You are in love with Rebecca Orsolini" << std::endl;
        //});

        windowThread.windowOpened = true;
        cv.notify_one();
        window.windowLoop();
        windowThread.window = nullptr;
    }, name, width, height);

    //  Transfer the thread pointer (see if I can do this more elegantly)
    windowThread.thread = std::unique_ptr<std::thread>(t);

    //  Block until the window is open, and window* has a value in windowThread
    std::unique_lock<std::mutex> lock(mutex);
    cv.wait(lock, [&windowThread]{ return windowThread.windowOpened; });
    windows.push_back(std::move(windowThread));
    lock.unlock();
    */
}

void RebeccaUI::WindowManager::CloseWindow(int sdlWinId) {
    /*
    auto iter = windows.begin();
    while (iter != windows.end()) {
        if (iter->window && iter->window->GetWindowId() == sdlWinId) {
            iter->window->stopLoop();
            iter->thread->join();
            windows.erase(iter);
            break;
        }
        iter = std::next(iter);
    }
    */
}

bool RebeccaUI::WindowManager::IsNoWindows() const {
    return ((windows.size() < 1) && singleWindow == nullptr);
}

void RebeccaUI::WindowManager::AddSingleWindow() {
    if (!singleWindow) {
        singleWindow = factory->CreateSynchronousWindow();
    }
}

RebeccaUI::IWindow* RebeccaUI::WindowManager::GetWindow(int sdlWinId) {
    /*
    auto iter = windows.begin();
    while (iter != windows.end()) {
        if (iter->window && iter->window->GetWindowId() == sdlWinId) {
            return iter->window;
        }
        iter = std::next(iter);
    }
    return nullptr;
    */
}

RebeccaUI::IWindow* RebeccaUI::WindowManager::GetWindow() {
    return singleWindow.get();
}

void RebeccaUI::WindowManager::UpdateAll() {
    /*
    auto winIter = windows.begin();
    while (winIter != windows.end()) {
        if (winIter->window) {
            winIter->window->update();
            ++winIter;
        }
    }
    */
}

void RebeccaUI::WindowManager::registerEvents() {
    if (!eventTent) {
        std::cout << "Event tent is null" << std::endl;
        return;
    }

    eventTent->AddEventResponse(EventTypes::CLOSE_BUTTON_PRESSED_EVENT, [this](std::unique_ptr<IEvent> event){
        auto evt = Utils::CastUniquePtr<IEvent, CloseButtonPressedEvent>(std::move(event));
            std::cout << "SDL Close event (Window Manager Event Tent)" << std::endl;
        
        // Get the event's window ID
        int winId = evt->GetWindowID();

        //  A simple test for making sure a basic event works
        //    The following two lines are to be removed later
        //    There will be no 'singleWindow', just a list of windows
        singleWindow.reset(nullptr);
        return;

        //  This could (should?) be its own function
        auto winPtr = windows.begin();
        while (winPtr != windows.end()) {
            if (winId == (*winPtr)->GetWindowId()) {
                break;
            }
        }

        if (winPtr != windows.end()) {
            //  Use winPtr to access the window
            //  Add the event to the window's eventReceiver
            (*winPtr)->RecieveEvent(std::move(event));
        }
    });
}
