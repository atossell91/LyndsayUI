#pragma once

#include "IGraphics.h"

namespace NSLyndsayUI {
    class IDrawable {
    public:
        virtual ~IDrawable() {}
        //  Public stuff here
        virtual void Draw(IGraphics* graphics) = 0;
    };
} // LyndsayUI
