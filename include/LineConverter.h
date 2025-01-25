#pragma once

#include "Point.h"
#include "Line.h"
#include "Vector2D.h"

namespace NSLyndsayUI {
    namespace LineConverter {
        Vector2D LineToVector2D(const Line& line) {
            Vector2D vec;
            vec.X = line.PEnd.X - line.PStart.X;
            vec.Y = line.PEnd.Y - line.PStart.Y;

            return vec;
        }

        Point Vector2DToPoint(const Vector2D& vector, Point offset) {
            Point point;

            point.X = vector.X + offset.X;
            point.Y = vector.Y + offset.Y;

            return point;
        }

        Vector2D PointToVector2D(const Point& point) {
            return Vector2D(point.X, point.Y);
        }

        Line Vector2DToLine(const Vector2D& vector, const Point& offset) {
            Point pstart;
            pstart.X = offset.X;
            pstart.Y = offset.Y;

            Point pend;
            pend.X = offset.X + pend.X;
            pend.Y = offset.Y + pend.Y;

            Line line(pstart, pend);
            
            return line;
        }
    }
} // NSLyndsayUI
