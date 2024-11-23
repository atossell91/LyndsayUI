#pragma once

#include "Window/IWindow.h"
#include "Event/IEventReceiver.h"

namespace LyndsayUI {
    class IWindowManager : public IEventReceiver {
    public:
        virtual ~IWindowManager() {}
        //  Public stuff here
        virtual IWindow* GetWindow(int windowId) = 0;
    };
} // LyndsayUI
