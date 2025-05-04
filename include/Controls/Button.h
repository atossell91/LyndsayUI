#pragma once

#include "Drawing/IGraphics.h"
#include "Drawing/Colours.h"
#include "Controls/IControl.h"

namespace NSLyndsayUI {
    class Button : public IControl {
    private:
        //  Private stuff here
        TransformParams fillParams;
        Colour fillColour = Colours::LightGrey;
    public:
        //  Public stuff here
        void SetWidth(float width) { fillParams.setXscale(width); }
        void SetHeight(float height) { fillParams.setYscale(height); }
        void SetXpos(float xpos) { fillParams.setXtranslation(xpos); }
        void SetYPos(float ypos) { fillParams.setYtranslation(ypos); }

        void Draw(IGraphics* graphics);
    };
} // NSLyndsayUI
