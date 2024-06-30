#pragma once

#include <cstdint>


namespace RixinSDL {
    class Colour {
     private:
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
     public:
        uint8_t GetRed() { return r; }
        void SetRed(uint8_t val) { r = val; }
        uint8_t GetGreen() { return g; }
        void SetGreen(uint8_t val) { g = val; }
        uint8_t GetBlue() { return b; }
        void SetBlue(uint8_t val) { b = val; }
        uint8_t GetAlpha() { return a; }
        void SetAlpha(uint8_t val) { a = val; }
        void SetColour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
            r = red;
            g = green;
            b = blue;
            a = alpha;
        }

        friend class DrawHelper;
    };
}
