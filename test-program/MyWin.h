#pragma once

#include "Window/ImmediateWindow.h"

namespace NSLyndsayUI {
    class MyWin : public ImmediateWindow {
    private:
        //  Private stuff here
        bool isSet = false;
        BufferedImage img;
        int tickCount = 0;
    public:
        //  Public stuff here
        void Setup() {
            //img = this->GetGraphics()->BufferImage("/home/ant/Pictures/celluloid-shot0044.jpg");
        }

        void Draw() {
            this->GetGraphics()->Clear();
            TransformParams imgParams, spiralParams;

            constexpr float num = 1920.0/1080.0;
            imgParams.setXscale(num);;
            Rectangle rSource(0, 0, img.getWidth(), img.getHeight());
            Rectangle rDest(0, 0, 0, 0);

            //this->GetGraphics()->DrawImage(img, rSource, rDest, imgParams);

            spiralParams.setXtranslation(-0.28);
            spiralParams.setYtranslation(0.32);
            spiralParams.setZrotation(tickCount);
            this->GetGraphics()->DrawSpiral(spiralParams);

            this->GetGraphics()->SwapBuffers();
            ++tickCount;
        }
    };
} // NSLyndsayUI
