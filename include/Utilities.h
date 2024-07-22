#pragma once

#include <SDL3/SDL.h>

namespace RixinSDL {
    namespace Utilities {
        char* VerticalFlipImg(char** pixels, int width, int height, int bitsPerPixel);
        void FlipImageSurface(SDL_Surface* sfc);
    }
}
