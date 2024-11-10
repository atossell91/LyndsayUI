#pragma once

#include "Window/IWindow.h"
#include "Event/IEventReceiver.h"

namespace RebeccaUI {
    class IRebeccaWindow : public IWindow, public IEventReceiver {
    public:
        virtual ~IRebeccaWindow() {}
        //  Public stuff here
    };
} // RebeccaUI
