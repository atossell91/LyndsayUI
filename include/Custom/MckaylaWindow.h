#pragma once

#include "Window/CustomWindowBase.h"

namespace NSLyndsayUI {
    class MckaylaWindow : public CustomWindowBase {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        void Close() {
            window->Close();
        }
    };
} // LyndsayUI
