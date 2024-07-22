#include "../include/Utilities.h"

void RixinSDL::Utilities::FlipImageSurface(SDL_Surface* sfc) {
    int bytesPerPixel = sfc->format->bytes_per_pixel;
    int rowWidth = sfc->w * bytesPerPixel;

    char* pixels = (char*)sfc->pixels;

    int yTop = 0;
    int yBottom = sfc->h -1;
    while (yTop <= yBottom) {
        for (int x =0; x < rowWidth; ++x) {
            int topIndex = yTop * rowWidth + x;
            int bottomIndex = yBottom * rowWidth + x;

            //  Do the swap
            char tempByte = pixels[topIndex];
            pixels[topIndex] = pixels[bottomIndex];
            pixels[bottomIndex] = tempByte;
        }
        ++yTop;
        --yBottom;
    }
}
