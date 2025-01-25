#pragma once

#include <SDL3/SDL.h>
#include <memory>

#include "Vector2D.h"

namespace NSLyndsayUI {
    namespace Utilities {
        char* VerticalFlipImg(char** pixels, int width, int height, int bitsPerPixel);

        void FlipImageSurface(SDL_Surface* sfc);

        template <typename F, typename T>
        std::unique_ptr<T> CastUniquePtr(std::unique_ptr<F> ptr) {
            auto p = std::unique_ptr<T>(static_cast<T*>(ptr.release()));
            return std::move(p);
        }

        Vector2D NormalizeVector(const Vector2D& vector);

        Vector2D CalcNormal(const Vector2D& vector);
    }
}
