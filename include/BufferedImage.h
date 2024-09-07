#pragma once

#include <stddef.h>
#include "GL/gl.h"

namespace RixinSDL {
    class BufferedImage {
    
    public:
        BufferedImage() {}
        BufferedImage(GLuint buffer, size_t width, size_t height) :
            bufferId{buffer}, width{width}, height{height} {}

        size_t getWidth() { return width; }
        size_t getHeight() { return height; }
        GLuint getBufferId() { return bufferId; }
    private:
        size_t width = -1;
        size_t height = -1;
        GLuint bufferId  = -1;
    };
}