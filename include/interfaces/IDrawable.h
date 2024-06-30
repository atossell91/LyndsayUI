#pragma once

#include "../DrawHelper.h"

class DrawHelper;

namespace RixinSDL {
    class IDrawable {
    public:
        virtual ~IDrawable() {}
        virtual void Draw(DrawHelper* drawHelper) = 0;
    };
}
