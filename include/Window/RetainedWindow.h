#pragma once

#include "Window/ImmediateWindow.h"

namespace NSLyndsayUI {
    class RetainedWindow : public CustomWindow {
    private:
        //  Private stuff here
    public:
        //  Public stuff here

        friend class CustomWindowFactory;
    };
} // NSLyndsayUI
