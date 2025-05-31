#pragma once

#include <vector>
#include <cstdint>

namespace NSLyndsayUI {
    enum ImageRowOrder {
        TopToBottom = 0,
        BottomToTop = 1
    };

    enum PixelColourType {
        Single = 0,
        Dual = 1,
        Tri = 2,
        Quad = 3
    };

    struct ImageData {
    public:
        //  Public stuff here
        size_t ImageWidth = 0; // The total image width
        size_t RowWidth = 0; // The image width + any byte padding
        ImageRowOrder RowOrder = TopToBottom;
        size_t RowCount = 0;
        std::vector<char> Buffer;
        PixelColourType ColourType = PixelColourType::Quad;
    };
} // NSLyndsayUI
