#pragma once

namespace LyndsayUI {
    class IWindow {
    public:
        virtual ~IWindow() {}
        virtual int GetWindowId() = 0;
        //  Public stuff here
    };
} // LyndsayUI
