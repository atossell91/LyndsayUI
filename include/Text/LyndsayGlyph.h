#pragma once

#include <vector>
#include <cstdint>

#include "ImageData.h"

namespace NSLyndsayUI {
    struct LyndsayGlyph {
        //  Public stuff here
        ImageData data;
        int Width = 0;
        int Height = 0;
        int BearingX = 0;
        int BearingY = 0;
        int Advance = 0;
    };
} // NSLyndsayUI
