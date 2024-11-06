#pragma once

#include "IGraphics.h"

namespace RebeccaUI {
    class IDrawable {
    public:
        virtual ~IDrawable() {}
        //  Public stuff here
        virtual void Draw(IGraphics* graphics) = 0;
    };
} // RebeccaUI
