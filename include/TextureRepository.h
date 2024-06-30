#pragma once

#include <map>
#include <SDL3/SDL.h>

#include "Image.h"
#include "ImageReference.h"

namespace RixinSDL {
    class TextureRepository {
     private:
        SDL_Renderer* renderer;
        std::map<int, SDL_Texture*> textures;
        int currentId = 0;
        int incrementId() { return ++currentId; }
     public:
        TextureRepository(SDL_Renderer* r) : renderer{r} {}
        ImageReference AddImage(const Image& image);
        void RemoveImage(const ImageReference& imgRef);
        SDL_Texture* AccessTexture(const ImageReference& imgRef);
    };
}