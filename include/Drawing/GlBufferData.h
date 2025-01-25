#pragma once

#include <vector>

#include "Point.h"

namespace NSLyndsayUI {
    class GlBufferData {
    private:
        //  Private stuff here
        std::vector<float> data;
        int bufferId;
        int shaderId;
    public:
        //  Public stuff here
        void AddPoint(const Point& p) {
            data.push_back(p.X);
            data.push_back(p.Y);
            
            data.push_back(0.0f);
            data.push_back(0.0f);
            data.push_back(0.0f);
        }
    };
} // NSLyndsayUI
