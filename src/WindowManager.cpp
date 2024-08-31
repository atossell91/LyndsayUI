#include <string>
#include <thread>

#include "../include/WindowManager.h"

#include <iostream>

void RixinSDL::WindowManager::AddWindow(const std::string& name, int width, int height) {

    WindowThread windowThread;
    std::thread* t = new std::thread([this, &windowThread](const std::string& name, int width, int height){
        Window window(name, width, height);
        windowThread.window = &window;
        window.windowLoop();
        windowThread.window = nullptr;
    }, name, width, height);
    windows.push_back(std::move(windowThread));
}

void RixinSDL::WindowManager::CloseWindow(int sdlWinId) {
    auto iter = windows.begin();
    while (iter != windows.end()) {
        if (iter->window != nullptr && iter->window->GetWindowId() == sdlWinId) {
            iter->window->stopLoop();
            iter->thread->join();
            windows.erase(iter);
            break;
        }
        iter = std::next(iter);
    }
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
