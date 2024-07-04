#include "../include/TextureRepository.h"

#include <map>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "../include/Image.h"
#include "../include/ImageReference.h"

using namespace RixinSDL;

ImageReference TextureRepository::addTexture(SDL_Texture* texture) {
    int id = incrementId();
    textures.emplace(id, texture);
    ImageReference ref(id, 1, 1);
    return ref;
}

ImageReference TextureRepository::AddImage(const Image& image) {
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image.surface);
    return addTexture(texture);
}

ImageReference TextureRepository::AddImage(const char* path) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, path);
    return addTexture(texture);
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
