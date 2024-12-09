#pragma once

#include <memory>

#include "Drawing/IGraphics.h"

namespace NSLyndsayUI {
    class IWindow {
    public:
        //  Public stuff here
        virtual ~IWindow() {}
        virtual int GetWindowId() = 0;
        virtual void Close() = 0;
        virtual IGraphics* GetGraphics() = 0;
    };
} // LyndsayUI
