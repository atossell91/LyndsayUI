#pragma once

#include "TransformParams.h"

namespace RixinSDL {
    class IGraphics {
    public:
        virtual ~IGraphics() {}
        //  Public stuff here
        virtual void DrawRectangle(const TransformParams& params) = 0;
        virtual void DrawImage(const std::string& imgPath) = 0;
        virtual void DrawString() = 0;
        virtual void DrawLine(const TransformParams& params) = 0;
        virtual void DrawSpiral(const TransformParams& params) = 0;
        virtual void Clear() = 0;
    };
} // RixinSDL
