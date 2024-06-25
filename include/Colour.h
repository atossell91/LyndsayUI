#pragma once

namespace Colour {
    struct Colour {
        int Red = 0;
        int Green = 0;
        int Blue = 0;
        int Alpha = 0;
    };

    Colour FromName(const char* name);
}
