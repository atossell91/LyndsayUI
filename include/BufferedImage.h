#include <stddef.h>
#include "GL/gl.h"

namespace RixinSDL {
    class BufferedImage {
    
    public:
        BufferedImage(GLuint buffer, size_t width, size_t height) :
            bufferId{buffer}, width{width}, height{height} {}

        size_t getWidth() { return width; }
        size_t getHeight() { return height; }
        GLuint getBufferId() { return bufferId; }
    private:
        unsigned int imageId;
        size_t width;
        size_t height;
        GLuint bufferId  = -1;
    };
}