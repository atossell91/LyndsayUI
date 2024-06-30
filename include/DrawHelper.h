#pragma once

#include <map>
#include <SDL3/SDL.h>

#include "Colour.h"
#include "Point.h"
#include "Rectangle.h"
#include "Image.h"
#include "ImageReference.h"
#include "TextureRepository.h"

namespace RixinSDL {
    class DrawHelper {
     private:
        SDL_Renderer* renderer;
        TextureRepository* textureRepo;

        void SetTextureList(std::map<int, SDL_Texture*>* list);
     public:
        DrawHelper(SDL_Renderer* r, TextureRepository* repo) : renderer{r}, textureRepo{repo} {}
        void DrawLine(const Point& p1, const Point& p2, const Colour& colour) const;
        void FillRectangle(const Rectangle& rectangle, const Colour& colour) const;
        void DrawImage(const ImageReference& imgRef, const Rectangle& rectangle) const;

        friend class DrawManager;
    };
}
