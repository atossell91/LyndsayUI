#pragma once

#include "Point.h"

#include "Vector2D.h"

namespace NSLyndsayUI {
    struct Line {
    public:
        //  Public stuff here
        Line() {}

        Line(Point pstart, Point pend) : PStart{pstart}, PEnd{pend} {}

        Point PStart;
        Point PEnd;
    };
} // NSLyndsayUI
