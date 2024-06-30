#pragma once

#include <SDL3/SDL.h>
#include <list>

#include "DrawHelper.h"
#include "interfaces/IDrawable.h"
#include "Image.h"
#include "ImageReference.h"
#include "TextureRepository.h"

namespace RixinSDL {

    class DrawManager {
     private:
        SDL_Renderer* renderer;
        TextureRepository textureRepo;
        DrawHelper drawHelper;
        std::list<IDrawable*> drawables;

        // Creates the DrawHelper from the provided renderer
        DrawManager(SDL_Renderer* r) : renderer{r}, 
        drawHelper{DrawHelper(renderer, textureRepo)},
        textureRepo{TextureRepository(renderer)} {}
     public:
        ~DrawManager();
        ImageReference AddImage(const Image& image);
        void RemoveImage(const ImageReference& imageRef);
        void AddDrawable(IDrawable* drawable);
        void RemoveDrawable(IDrawable* drawable);
        void DrawEverything();

        // Factory function because the window is not a part of the class
        //  but is used to construct it. The default constructor is private.
        // Also creates a renderer (from the window) and a DrawHelper using
        //  the renderer. (Because they all use the same renderer).
        static DrawManager CreateFromWindow(SDL_Window* window);
    };
}
