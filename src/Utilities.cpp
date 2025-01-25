#include "../include/Utilities.h"

#include <cmath>

#include "Point.h"
#include "Vector2D.h"

using namespace NSLyndsayUI;

void NSLyndsayUI::Utilities::FlipImageSurface(SDL_Surface* sfc) {
    int bytesPerPixel = SDL_BITSPERPIXEL(sfc->format)/8;
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



Vector2D Utilities::NormalizeVector(const Vector2D& vector) {
    float lengthSq = vector.X * vector.X + vector.Y * vector.Y;
    float length = std::sqrt(lengthSq);

    Vector2D vec;
    vec.X = vector.X / length;
    vec.Y = vector.Y / length;

    return vec;
}

Vector2D Utilities::CalcNormal(const Vector2D& vector) {
    Vector2D vec;
    vec.X = -vector.X;
    vec.Y = vector.Y;

    vec = NormalizeVector(vec);

    return vec;
}
