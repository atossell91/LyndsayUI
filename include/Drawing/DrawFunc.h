#pragma once

#include <functional>

#include "Drawing/IDrawable.h"

namespace NSLyndsayUI {
    class DrawFunc : public IDrawable {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        std::function<void(IGraphics*)> DrawFunction;
        void Draw(IGraphics* graphics) {
            DrawFunction(graphics);
        }
    };
} // LyndsayUI
