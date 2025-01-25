#pragma once

namespace NSLyndsayUI {
    struct Point {
        Point() {}
        Point(float x, float y) : X{x}, Y{y} {}
        
        float X = 0.0f;
        float Y = 0.0f;
    };
}
