#pragma once

#include "Rectangle.h"
#include "TransformParams.h"
#include "BufferedImage.h"

namespace RixinSDL {
    class IGraphics {
    public:
        virtual ~IGraphics() {}
        //  Public stuff here
        virtual BufferedImage BufferImage(const std::string& imgPath) = 0;
        virtual void DrawRectangle(const TransformParams& params) = 0;
        virtual void DrawImage(BufferedImage image, 
            const Rectangle& sourceRect, const Rectangle& destRect, const TransformParams& params) = 0;
        virtual void DrawString() = 0;
        virtual void DrawLine(const TransformParams& params) = 0;
        virtual void DrawSpiral(const TransformParams& params) = 0;
        virtual void Clear() = 0;
    };
} // RixinSDL
