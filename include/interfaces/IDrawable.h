#pragma once

#include "../DrawHelper.h"

class DrawHelper;

namespace RixinSDL {
    class IDrawable {
    public:
        virtual ~IDrawable() {}
        virtual void Draw(const DrawHelper& drawHelper) = 0;
    };
}
