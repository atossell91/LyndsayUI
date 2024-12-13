#pragma once

#include <string>

#include "Rectangle.h"
#include "TransformParams.h"
#include "BufferedImage.h"
#include "Drawing/Colour.h"

namespace NSLyndsayUI {
    class IGraphics {
    public:
        virtual ~IGraphics() {}
        //  Public stuff here
        virtual BufferedImage BufferImage(const std::string& imgPath) = 0;
        virtual void DrawRectangle(const Colour& colour, const TransformParams& params) = 0;
        virtual void DrawImage(BufferedImage image, 
            const Rectangle& sourceRect, const Rectangle& destRect, const TransformParams& params) = 0;
        virtual void DrawString() = 0;
        virtual void DrawLine(const Colour& colour, const TransformParams& params) = 0;
        virtual void DrawSpiral(const Colour& colour, const TransformParams& params) = 0;
        virtual void Clear() = 0;
        virtual void SwapBuffers() = 0;
        virtual void SetBackColour(const Colour&) = 0;
    };
} // LyndsayUI
