#pragma once

#include <SDL3/SDL_rect.h>

namespace RixinSDL {
    class Point {
     private:
        SDL_FPoint point;
     public:
        float GetX() { return point.x; }
        void SetX(float val) { point.x = val; }
        float GetY() { return point.y; }
        void SetY(float val) { point.y = val; }

        friend class DrawHelper;
    };
}
