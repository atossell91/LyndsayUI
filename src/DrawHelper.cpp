#include "../include/DrawHelper.h"

#include <SDL3/SDL.h>

#include "../include/Point.h"
#include "../include/Rectangle.h"
#include "../include/Image.h"
#include "ImageReference.h"

using namespace RixinSDL;

void DrawHelper::FillRectangle(const Rectangle& rectangle, const Colour& colour) const {
    SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
    SDL_RenderFillRect(renderer, &rectangle.rectangle);
}

void DrawHelper::DrawImage(const ImageReference& imageRef, const Rectangle& rectangle) const {
    SDL_Texture* texture = textureRepo.AccessTexture(imageRef);

    if (texture != nullptr) {
        SDL_RenderTexture(renderer, texture, NULL, &rectangle.rectangle);
    }
}
