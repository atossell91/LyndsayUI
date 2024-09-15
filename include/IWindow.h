#pragma once

#include "IDrawable.h"

namespace RixinSDL {
    class IWindow {
    public:
        virtual ~IWindow() {}
        //  Public stuff here
        virtual void Update() = 0;
    };
} // RixinSDL
