#pragma once

#include <string>
#include <SDL3/SDL.h>

namespace NSLyndsayUI
{
    class Image {
     private:
        SDL_Surface* surface;
     public:
        int GetWidth() const;
        int GetHeight() const;
        ~Image();
        static Image LoadImage(const std::string& path);

        friend class TextureRepository;
    };
} // namespace NSLyndsayUI

