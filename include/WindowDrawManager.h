#pragma once

#include <list>
#include <memory>

#include "../include/DrawableBase.h"

namespace RixinSDL {
    class WindowDrawManager {
    private:
        std::list<std::shared_ptr<DrawableBase>> drawables;

    public:
        void drawAll();
    };
}
