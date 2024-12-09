#pragma once

#include <stddef.h>

namespace NSLyndsayUI {
    class BufferedImage {
    
    public:
        BufferedImage() {}
        BufferedImage(int buffer, size_t width, size_t height) :
            bufferId{buffer}, width{width}, height{height} {}

        size_t getWidth() { return width; }
        size_t getHeight() { return height; }
        int getBufferId() { return bufferId; }
    private:
        size_t width = -1;
        size_t height = -1;
        int bufferId  = -1;
    };
}