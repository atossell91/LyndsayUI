#pragma once

#include "Window/IWindow.h"

namespace LyndsayUI {
    class IWindowManager {
    public:
        virtual ~IWindowManager() {}
        //  Public stuff here
        virtual IWindow* GetWindow(int windowId) = 0;
    };
} // LyndsayUI
