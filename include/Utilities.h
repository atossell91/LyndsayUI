#pragma once

#include <SDL3/SDL.h>

namespace LyndsayUI {
    namespace Utilities {
        char* VerticalFlipImg(char** pixels, int width, int height, int bitsPerPixel);
        void FlipImageSurface(SDL_Surface* sfc);
    }
}
