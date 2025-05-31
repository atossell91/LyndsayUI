#pragma once

#include <string>

#include "Rectangle.h"
#include "TransformParams.h"
#include "BufferedImage.h"
#include "Drawing/Colour.h"
#include "Point.h"
#include "PointPath.h"

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
        virtual void DrawLine(
            const Point& p1, const Point& p2, float thickness,
            const Colour& colour, const TransformParams& params) = 0;
        virtual void DrawSpiral(const Colour& colour, const TransformParams& params) = 0;
        virtual void DrawPath(PointPath& path, const Colour& Colour, float thickness) = 0;
        virtual void Clear() = 0;
        virtual void SwapBuffers() = 0;
        virtual void SetBackColour(const Colour&) = 0;
        virtual void FillArc(float startAngle, float endAngle, float rad, const Colour& colour, const TransformParams& params) = 0;
    };
} // LyndsayUI
