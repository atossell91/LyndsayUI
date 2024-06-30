#pragma once

#include <SDL3/SDL.h>

namespace RixinSDL {
    class Rectangle {
     private:
        SDL_FRect rectangle;
     public:
        Rectangle() {
            rectangle.x = 0;
            rectangle.y = 0;
            rectangle.w = 0;
            rectangle.h = 0;
        }

        float GetWidth() { return rectangle.w; }
        void SetWidth(float val) { rectangle.w = val; }
        float GetHeight() { return rectangle.h; }
        void SetHeight(float val) { rectangle.h = val; }
        float GetX() { return rectangle.x; }
        void SetX(float val) { rectangle.x = val; }
        float GetY() { return rectangle.y; }
        void SetY(float val) { rectangle.y = val; }

        friend class DrawHelper;
    };
}
