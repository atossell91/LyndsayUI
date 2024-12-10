#pragma once

#include "Window/ImmediateWindow.h"
#include "Event/EventData/MouseButtonEventData.h"

namespace NSLyndsayUI {
    class MyWin : public ImmediateWindow {
    private:
        //  Private stuff here
        bool isSet = false;
        BufferedImage img;
        int tickCount = 0;
        float mouseX = 0;
        float mouseY = 0;
    public:
        //  Public stuff here
        void Setup() {
            //img = this->GetGraphics()->BufferImage("/home/ant/Pictures/celluloid-shot0044.jpg");
            MouseButtonDown.AddEventHandler([this](auto d){MouseDownHandler(d);});
            MouseMoved.AddEventHandler([this](auto d){MouseMoveHandler(d);});
        }

        float mapCoord(float absCoord, float magnitude) {
            float half = magnitude/2;
            float pos = (absCoord-half)/half;
            return pos;
        }

        void MouseDownHandler(MouseButtonEventData d) {
        }

        void MouseMoveHandler(MouseMovedEventData d) {
            mouseX = mapCoord(d.MouseX, 1920);
            mouseY = -mapCoord(d.MouseY, 1080);
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
            this->GetGraphics()->DrawSpiral(spiralParams);

            TransformParams myParams;
            myParams.setXtranslation(mouseX);
            myParams.setYtranslation(mouseY);
            //this->GetGraphics()->DrawRectangle(myParams);

            this->GetGraphics()->SwapBuffers();

            ++tickCount;
        }
    };
} // NSLyndsayUI
