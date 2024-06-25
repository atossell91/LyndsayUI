#pragma once

#include <SDL3/SDL.h>

class IDrawable {
 public:
    virtual ~IDrawable() {}
    virtual void Draw(SDL_Renderer* render) = 0;
};
