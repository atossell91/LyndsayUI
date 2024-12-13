#pragma once

#include "Drawing/GlGraphics.h"
#include "Drawing/Colours.h"
#include "Drawing/BufferedImage.h"
#include "Rectangle.h"

namespace NSLyndsayUI {
    class MyRect {
    private:
        //  Private stuff here
        BufferedImage img;
        bool hasImg = false;
    public:
        //  Public stuff here
        float speed = 0.02;
        char sign = 1;

        float xPos = 0.0;
        float yPos = 0.0;

        char hDir = 0;
        char vDir = 0;

        float rot = 0.0;

        TransformParams p;
        Rectangle rectangle = Rectangle(10, 10, 10, 10);

        void setImg(BufferedImage newImg) {
            img = newImg;
            hasImg = true;
        }

        void draw(IGraphics* graphics) {
            sign = hDir != 0 ? hDir : sign;
            p.setYrotation(-rot);
            p.setXrotation(rot);
            p.setXscale(0.2 * sign);
            p.setYscale(0.2);
            p.setXtranslation(xPos);
            p.setYtranslation(yPos);

            if (hasImg) {
                graphics->DrawImage(img, rectangle, rectangle, p);
            }
            else {
                graphics->DrawRectangle(Colours::LightGrey, p);
            }
        }
    };
} // NSLyndsayUI
