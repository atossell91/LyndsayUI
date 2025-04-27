#pragma once

#include "Window/CustomWindow.h"

namespace NSLyndsayUI {
    class ImmediateWindow : public CustomWindow {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        virtual void Update() {}
        virtual void Draw() {}

        virtual void RenderFrame() {
            this->GetGraphics()->Clear();
            Draw();
            this->GetGraphics()->SwapBuffers();
        }

        friend class CustomWindowFactory;
    };
} // NSLyndsayUI
