#pragma once

#include "Window/IWindow.h"
#include "Event/IEventReceiver.h"

namespace LyndsayUI {
    class ILyndsayWindow : public IWindow, public IEventReceiver {
    public:
        virtual ~ILyndsayWindow() {}
        //  Public stuff here
    };
} // LyndsayUI
