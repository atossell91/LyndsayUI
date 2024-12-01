#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "Utils.h"
#include "Window/WindowManager.h"
#include "Window/IWindow.h"

#include <iostream>

void LyndsayUI::WindowManager::AddWindow(const std::string& name, int width, int height) {
    auto win = factory->CreateAsynchronousWindow();
    singleWindow = std::move(win);
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

void LyndsayUI::WindowManager::CloseWindow(int sdlWinId) {
    singleWindow->Close();
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

bool LyndsayUI::WindowManager::HasWindows() {
    return ((windows.size() < 0) || singleWindow);
}

void LyndsayUI::WindowManager::AddSingleWindow() {
    if (!singleWindow) {
        singleWindow = factory->CreateAsynchronousWindow();
    }
}

LyndsayUI::IWindow* LyndsayUI::WindowManager::GetWindow(int sdlWinId) {
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

LyndsayUI::IWindow* LyndsayUI::WindowManager::GetWindow() {
    return singleWindow.get();
}

void LyndsayUI::WindowManager::UpdateAll() {
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

void LyndsayUI::WindowManager::initEvents() {
    WindowCloseButtonClickedEvent += [this](auto data){
        singleWindow->Close();
    };
}
