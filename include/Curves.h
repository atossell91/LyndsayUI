#pragma once

#include <glm/glm.hpp>

#include "Point.h"
#include "Vector2D.h"

namespace NSLyndsayUI {
    namespace Curves {
        //  Public stuff here
        // Linear Bézier (2 points)
        inline Point evaluateLinear(Point P0, Point P1, float t) {
            Vector2D vec = Vector2D(P0.X, P0.Y) * (1.0f - t) + Vector2D(P1.X, P1.Y) * t;
            return Point(vec.X, vec.Y);
        }

        // Quadratic Bézier (3 points)
        inline Point evaluateQuadratic(Point P0, Point P1, Point P2, float t) {
            float u = 1.0f - t;
            Vector2D vec = Vector2D(P0.X, P0.Y) * (u * u) + Vector2D(P1.X, P1.Y) * (2.0f * u * t) +
                Vector2D(P2.X, P2.Y) * (t * t);
            return Point(vec.X, vec.Y);
        }

        // Cubic Bézier (4 points)
        inline Point evaluateCubic(Point P0, Point P1, Point P2, Point P3, float t) {
            float u = 1.0f - t;
            float uu = u * u;
            float tt = t * t;
            Vector2D vec = Vector2D(P0.X, P0.Y) * (u * uu) + Vector2D(P1.X, P1.Y) * (3.0f * uu * t) + 
                Vector2D(P2.X, P2.Y) * (3.0f * u * tt) + Vector2D(P3.X, P3.Y) * (t * tt);
            return Point(vec.X, vec.Y);
        }

    };
} // NSLyndsayUI
