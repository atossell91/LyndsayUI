#include "../include/TextureRepository.h"

#include <map>

#include <SDL3/SDL.h>

#include "../include/Image.h"
#include "../include/ImageReference.h"

using namespace RixinSDL;

ImageReference TextureRepository::AddImage(const Image& image) {
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image.surface);
    int id = incrementId();
    textures.emplace(id, texture);
    ImageReference ref(id, image.GetWidth(), image.GetHeight());

    return ref;
}

void TextureRepository::RemoveImage(const ImageReference& imgRef) {
    SDL_Texture* tex = AccessTexture(imgRef);
    textures.erase(imgRef.GetId());
    SDL_DestroyTexture(tex);
}

SDL_Texture* TextureRepository::AccessTexture(const ImageReference& imgRef) {
    if (textures.find(imgRef.GetId()) == textures.end()) {
        return nullptr;
    }
    else {
        return textures[imgRef.GetId()];
    }
}
