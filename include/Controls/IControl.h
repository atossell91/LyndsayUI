#pragma once

#include "Drawing/IGraphics.h"

namespace NSLyndsayUI {
    class IControl {
    public:
        virtual ~IControl() {}
        //  Public stuff here
        virtual void Draw(IGraphics* graphics) = 0;
    };
} // NSLyndsayUI
