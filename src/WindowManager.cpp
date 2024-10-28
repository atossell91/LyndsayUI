#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "../include/WindowManager.h"

#include "Window.h"

#include <iostream>

std::unique_ptr<RixinSDL::Window> RixinSDL::WindowManager::windowFactory() {
    std::unique_ptr<Window> window = std::make_unique<Window>("Sammie is cute", 1920, 1080);

    window->GetEventProcessor().addEventHandler(SDL_EVENT_QUIT, [&window](std::unique_ptr<IEvent> d){
        std::cout << "Stopping" << std::endl;
        window->stopLoop();
    });

    return std::move(window);
}

void RixinSDL::WindowManager::AddWindow(const std::string& name, int width, int height) {

    WindowThread windowThread;

    //  Start the window thread
    std::thread* t = new std::thread([&windowThread, this](const std::string& name, int width, int height){
        Window window(name, width, height);
        {
            std::lock_guard<std::mutex> lg(mutex);
            windowThread.window = &window;
        }

        window.GetEventProcessor().addEventHandler(91,
        [](std::unique_ptr<IEvent> event){
            std::cout << "You are in love with promise" << std::endl;
        });

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
}

void RixinSDL::WindowManager::CloseWindow(int sdlWinId) {
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
}

bool RixinSDL::WindowManager::IsNoWindows() const {
    return ((windows.size() < 1) && singleWindow == nullptr);
}

void RixinSDL::WindowManager::AddSingleWindow() {
    if (!singleWindow) {
        singleWindow = windowFactory();
    }
}

RixinSDL::Window* RixinSDL::WindowManager::GetWindow(int sdlWinId) {
    auto iter = windows.begin();
    while (iter != windows.end()) {
        if (iter->window && iter->window->GetWindowId() == sdlWinId) {
            return iter->window;
        }
        iter = std::next(iter);
    }
    return nullptr;
}

RixinSDL::Window* RixinSDL::WindowManager::GetWindow() {
    return singleWindow.get();
}

void RixinSDL::WindowManager::UpdateAll() {
    auto winIter = windows.begin();
    while (winIter != windows.end()) {
        if (winIter->window) {
            winIter->window->update();
            ++winIter;
        }
    }
}
