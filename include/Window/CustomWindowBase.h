#pragma once

#include <memory>
#include <type_traits>

#include "Window/IWindow.h"

class LyndsayUI;

namespace NSLyndsayUI {
    class CustomWindowBase {
    private:
        //  Private stuff here
    protected:
        std::unique_ptr<IWindow> window;

        //template <typename T>
        friend class LyndsayUI;
    public:
        //  Public stuff here
    };
} // LyndsayUI
