#include "../include/WindowDrawManager.h"

using namespace RixinSDL;

void WindowDrawManager::drawAll() {
    for (auto drawable : drawables) {
        drawable->draw();
    }
}
