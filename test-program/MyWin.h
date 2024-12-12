#pragma once

#include "Window/ImmediateWindow.h"
#include "Event/EventData/MouseButtonEventData.h"
#include "MyRect.h"
#include "KeyValues.h"

namespace NSLyndsayUI {
    class MyWin : public ImmediateWindow {
    private:
        //  Private stuff here
        bool isSet = false;
        BufferedImage img;
        int tickCount = 0;
        float mouseX = 0;
        float mouseY = 0;

        bool wDown = false;
        bool aDown = false;
        bool sDown = false;
        bool dDown = false;

        MyRect rect;
    public:
        //  Public stuff here
        void Setup() {
            //img = this->GetGraphics()->BufferImage("/home/ant/Pictures/celluloid-shot0044.jpg");
            MouseButtonDown.AddEventHandler([this](auto d){MouseDownHandler(d);});
            MouseMoved.AddEventHandler([this](auto d){MouseMoveHandler(d);});
            KeyDown.AddEventHandler([this](auto d){KeyDownHandler(d);});
            KeyUp.AddEventHandler([this](auto d){KeyUpHandler(d);});
        }

        float mapCoord(float absCoord, float magnitude) {
            float half = magnitude/2;
            float pos = (absCoord-half)/half;
            return pos;
        }

        void KeyDownHandler(KeyboardEventData d) {
            if (d.key == KeyValues::Keyboard_W && !wDown) {
                wDown = true;
                rect.vVeloc = 0.01;
            }
            if (d.key == KeyValues::Keyboard_A && !aDown) {
                aDown = true;
                rect.hVeloc = -0.01;
            }
            if (d.key == KeyValues::Keyboard_S && !sDown) {
                sDown = true;
                rect.vVeloc = -0.01;
            }
            if (d.key == KeyValues::Keyboard_D && !dDown) {
                dDown = true;
                rect.hVeloc = 0.01;
            }
        }

        void KeyUpHandler(KeyboardEventData d) {
            if (d.key == KeyValues::Keyboard_W) {
                wDown = false;
            }
            if (d.key == KeyValues::Keyboard_A) {
                aDown = false;
            }
            if (d.key == KeyValues::Keyboard_S) {
                sDown = false;
            }
            if (d.key == KeyValues::Keyboard_D) {
                dDown = false;
            }

            if (!dDown && !aDown) {
                rect.hVeloc = 0.0;
            }

            if (!wDown && !sDown) {
                rect.vVeloc = 0.0;
            }
        }

        void MouseDownHandler(MouseButtonEventData d) {
        }

        void MouseMoveHandler(MouseMovedEventData d) {
            mouseX = mapCoord(d.MouseX, 1920);
            mouseY = -mapCoord(d.MouseY, 1080);
        }

        void Update() {
            rect.rot += 0.2;
            rect.xPos += rect.hVeloc;
            rect.yPos += rect.vVeloc;
        }

        void Draw() {
            this->GetGraphics()->Clear();
            TransformParams imgParams, spiralParams;

            constexpr float num = 1920.0/1080.0;
            imgParams.setXscale(num);;
            Rectangle rSource(0, 0, img.getWidth(), img.getHeight());
            Rectangle rDest(0, 0, 0, 0);

            //this->GetGraphics()->DrawImage(img, rSource, rDest, imgParams);

            spiralParams.setXtranslation(mouseX);
            spiralParams.setYtranslation(mouseY);
            spiralParams.setZrotation(tickCount);
            //this->GetGraphics()->DrawSpiral(spiralParams);

            TransformParams myParams;
            myParams.setXtranslation(mouseX);
            myParams.setYtranslation(mouseY);
            //this->GetGraphics()->DrawRectangle(myParams);

            rect.draw(this->GetGraphics());

            this->GetGraphics()->SwapBuffers();

            ++tickCount;
        }
    };
} // NSLyndsayUI
