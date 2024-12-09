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

        friend class CustomWindowFactory;
    };
} // NSLyndsayUI
