#pragma once

#include "Drawing/IDrawable.h"

namespace RebeccaUI {
    class IWindow {
    public:
        virtual ~IWindow() {}
        virtual int GetWindowId() = 0;
        //  Public stuff here
    };
} // RebeccaUI
