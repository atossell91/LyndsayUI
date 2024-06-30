#include "../include/DrawManager.h"

#include <SDL3/SDL.h>

#include "../include/Image.h"
#include "../include/ImageReference.h"

using namespace RixinSDL;

DrawManager::~DrawManager() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
}

ImageReference DrawManager::AddImage(const Image& image) {
    return textureRepo.AddImage(image);
}

void DrawManager::RemoveImage(const ImageReference& imageRef) {
    textureRepo.RemoveImage(imageRef);
}

void DrawManager::AddDrawable(IDrawable* drawable) {
    drawables.push_back(drawable);
}

void DrawManager::RemoveDrawable(IDrawable* drawable) {
    drawables.remove(drawable);
}

void DrawManager::DrawEverything() {
    for (auto drawable : drawables) {
        drawable->Draw(drawHelper);
    }
}

DrawManager DrawManager::CreateFromWindow(SDL_Window* window) {
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    DrawManager manager(renderer);

    return manager;
}
