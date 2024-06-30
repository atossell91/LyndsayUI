#include "../include/Image.h"

#include <string>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

using namespace RixinSDL;

int Image::GetHeight() const {
    if (surface != nullptr) {
        return surface->h;
    }
    else return -1;
}

int Image::GetWidth() const {
    if (surface != nullptr) {
        return surface->w;
    }
    else return -1;
}

Image Image::LoadImage(const std::string& path) {
    Image i;
    i.surface = IMG_Load(path.c_str());
    return i;
}

Image::~Image() {
    if (surface != nullptr) {
        SDL_DestroySurface(surface);
    }
}
