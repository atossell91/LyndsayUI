#pragma once

#include <vector>
#include <cstdint>

namespace NSLyndsayUI {
    enum GlyphRowOrder {
        TopToBottom = 0,
        BottomToTop = 1
    };

    struct GlyphData {
    public:
        //  Public stuff here
        size_t ImageWidth = 0; // The total image width
        size_t RowWidth = 0; // The image width + any byte padding
        GlyphRowOrder RowOrder = TopToBottom;
        size_t RowCount = 0;
        std::vector<char> Buffer;
    };
} // NSLyndsayUI
