#pragma once

#include <vector>

#include "Point.h"
#include "Line.h"

namespace NSLyndsayUI {
    class PointPath {
    private:
        //  Private stuff here
        std::vector<Point> points;
    public:
        //  Public stuff here
        auto begin() { return points.begin(); }
        auto end() { return points.end(); }

        void AddPoint (const Point& point) {
            points.push_back(point);
        }

        void RemoveLastPoint() { points.pop_back(); }

        Point& operator[](int index) { return points[index]; }

        bool GetLine(int startIndex, int endIndex, Line& line) {
            if (startIndex < 0 || endIndex > NumPoints() -2) {
                return false;
            }

            line = Line(points[startIndex], points[endIndex]);
            return true;
        }

        bool GetLine(int startIndex, Line& line) {
            // Need to handle out of bounds indices
            return GetLine(startIndex, startIndex+1, line);
        }

        size_t NumPoints() const {
            return points.size();
        }
    };
} // NSLyndsayUI
