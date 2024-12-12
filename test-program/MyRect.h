#pragma once

#include "Drawing/GlGraphics.h"

namespace NSLyndsayUI {
    class MyRect {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        float hVeloc = 0.0;
        float vVeloc = 0.0;

        float xPos = 0.0;
        float yPos = 0.0;

        float rot = 0.0;

        TransformParams p;

        void draw(IGraphics* graphics) {
            p.setYrotation(-rot);
            p.setXrotation(rot);
            p.setXscale(0.2);
            p.setYscale(0.2);
            p.setXtranslation(xPos);
            p.setYtranslation(yPos);
            graphics->DrawRectangle(p);
        }
    };
} // NSLyndsayUI
