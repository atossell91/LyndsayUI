#pragma once

#include <vector>

#include "Point.h"
#include "PointPath.h"
#include "Vector2D.h"

namespace NSLyndsayUI {
    using VertexBuffer = std::vector<float>;
    class PathDrawer {
    private:
        //  Private stuff here
        struct LineInfo {
            Line line;
            Vector2D normal;
        };

        bool getLineInfo(PointPath& points, int index, LineInfo& line);
        void CalcJoinPoint(LineInfo l1, LineInfo l2, float thickness, VertexBuffer& buffer);
        void CalcEndPoint(LineInfo l1, float thickness, VertexBuffer& buffer);
        void bufferPoint(const Point& point, VertexBuffer& buffer);
    public:
        //  Public stuff here
        VertexBuffer CreateVertices(PointPath& points, float thickness);
    };
} // NSLyndsayUI
