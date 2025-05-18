#pragma once

#include <vector>
#include <cstdint>

namespace NSLyndsayUI {
    struct LyndsayGlyph {
        //  Public stuff here
        std::vector<uint8_t> data;
        int Width = 0;
        int Height = 0;
        int BearingX = 0;
        int BearingY = 0;
        int Advance = 0;
    };
} // NSLyndsayUI
