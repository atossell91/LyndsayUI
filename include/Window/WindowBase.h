#pragma once

#include <memory>

#include "Window/IWindow.h"

namespace LyndsayUI {
    class WindowBase : public IWindow {
    private:
        //  Private stuff here
        int windowId;
    protected:
        WindowBase(int winId) : windowId{winId} {}
    public:
        //  Public stuff here
        int GetWindowId() { return windowId; }
    };
} // LyndsayUI
