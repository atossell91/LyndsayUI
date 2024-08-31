#include <string>

#include "../include/WindowManager.h"

#include <iostream>

void RixinSDL::WindowManager::AddWindow(const std::string& name, int width, int height) {
    windows.push_back(std::make_unique<Window>(name, width, height));
}

void RixinSDL::WindowManager::CloseWindow(int sdlWinId) {
    auto iter = windows.begin();
    while (iter != windows.end()) {
        if (iter->get()->GetWindowId() == sdlWinId) {
            (*iter)->stopLoop();
            windows.remove(*iter);
            break;
        }
        iter = std::next(iter);
    }
}

void RixinSDL::WindowManager::UpdateAll() {
    auto winIter = windows.begin();
    while (winIter != windows.end()) {
        (*winIter)->update();
        ++winIter;
    }
}
