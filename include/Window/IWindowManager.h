#pragma once

#include <string>

#include "Window/IWindow.h"

namespace LyndsayUI {
    class IWindowManager {
    public:
        virtual ~IWindowManager() {}
        //  Public stuff here
        virtual IWindow* GetWindow(int windowId) = 0;
        virtual bool HasWindows() = 0;
        virtual void AddWindow(const std::string& name, int width, int height) = 0;
    };
} // LyndsayUI
