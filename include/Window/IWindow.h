#pragma once

#include "Drawing/IDrawable.h"

namespace RebeccaUI {
    class IWindow {
    public:
        virtual ~IWindow() {}
        //  Public stuff here
        virtual void Update() = 0;
    };
} // RebeccaUI
