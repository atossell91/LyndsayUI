#include <string>

#include "../include/WindowStuff/WindowManager.h"

#include <iostream>

void RixinSDL::WindowManager::AddWindow(const std::string& name, int width, int height) {
    windows.push_back(std::make_unique<Window>(name, width, height));
}

void RixinSDL::WindowManager::CloseWindow(int sdlWinId) {
    auto iter = windows.begin();
    while (iter != windows.end()) {
        if (iter->get()->GetWindowId() == sdlWinId) {
            windows.remove(*iter);
            break;
        }
        iter = std::next(iter);
    }
}
