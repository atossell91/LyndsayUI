#pragma once

#include <memory>
#include <type_traits>

#include "Window/IWindow.h"
#include "LyndsayUI.h"

namespace NSLyndsayUI {
    class CustomWindowBase {
    private:
        //  Private stuff here
        std::unique_ptr<IWindow> window;

        //template <typename T>
        friend LyndsayUI;
    public:
        //  Public stuff here
    };
} // LyndsayUI
