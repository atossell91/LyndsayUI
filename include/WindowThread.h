#pragma once

#include <thread>
#include <memory>

#include "../include/Window.h"

namespace RixinSDL
{
    class WindowThread {
    public:
        Window* window = nullptr;
        std::unique_ptr<std::thread> thread = nullptr;
    };
} // namespace RixinSDL

