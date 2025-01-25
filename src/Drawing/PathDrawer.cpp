#include "Drawing/PathDrawer.h"

#include "Point.h"
#include "Vector2D.h"
#include "Utilities.h"
#include "PointPath.h"
#include "LineConverter.h"

#include <iostream>

using namespace NSLyndsayUI;

bool PathDrawer::getLineInfo(PointPath& points, int index, LineInfo& lineInfo) {
    if (index < 0 || index > points.NumPoints() - 2) {
        return false;
    }

    Line line(points[index], points[index+1]);

    Vector2D vec = LineConverter::LineToVector2D(line);
    vec = vec.CalcNormalVector();

    lineInfo.line = line;
    lineInfo.normal = vec;

    return true;
}

void PathDrawer::CalcEndPoint(LineInfo line, float thickness, VertexBuffer& buffer) {
    bufferPoint(
        LineConverter::Vector2DToPoint((line.normal * thickness), line.line.PStart),
        buffer
    );
    bufferPoint(
        LineConverter::Vector2DToPoint((line.normal * -thickness), line.line.PStart),
        buffer
    );
}

void PathDrawer::bufferPoint(const Point& point, VertexBuffer& buffer) {
    buffer.push_back(point.X);
    buffer.push_back(point.Y);
    buffer.push_back(0.0f);
    buffer.push_back(0.0f);
    buffer.push_back(0.0f);
}

void PathDrawer::CalcJoinPoint(LineInfo l1, LineInfo l2, float thickness, VertexBuffer& buffer) {
    ////  Average the two points and normalize the result
    Vector2D avg;
    avg.X = (l1.normal.X + l2.normal.X)/2;
    avg.Y = (l1.normal.Y + l2.normal.Y)/2;
    avg = avg.CalcNormalized();

    ////  Apply thickness and add the ponts to the buffer
    Vector2D vertexVector = (avg * thickness);
    bufferPoint(LineConverter::Vector2DToPoint(vertexVector, l1.line.PEnd), buffer);

    vertexVector = vertexVector * -1;
    bufferPoint(LineConverter::Vector2DToPoint(vertexVector, l1.line.PEnd), buffer);
}

VertexBuffer PathDrawer::CreateVertices(PointPath& points, float thickness) {
    VertexBuffer buffer;
    float halfThick = thickness/2;

    // Handle the first point
    LineInfo lineInfo;
    if (!getLineInfo(points, 0, lineInfo)) {
        return buffer;
    }
    // Add points to the buffer
    CalcEndPoint(lineInfo, halfThick, buffer);

    // Intermediate points
    LineInfo nextLine;
    for (int i = 1; i < points.NumPoints() -1 && getLineInfo(points, i, nextLine); ++i) {
        CalcJoinPoint(lineInfo, nextLine, halfThick, buffer);
        lineInfo = nextLine;
    }

    // Handle the last point
    LineInfo flippedLine = lineInfo;
    flippedLine.line = Line(lineInfo.line.PEnd, lineInfo.line.PStart);
    CalcEndPoint(flippedLine, halfThick, buffer);

    return buffer;
}
