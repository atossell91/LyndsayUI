#pragma once

#include <cstdint>


namespace RixinSDL {
    class Colour {
     private:
        int r = 0;
        int g = 0;
        int b = 0;
        int a = 255;
     public:
        int GetRed() { return r; }
        void SetRed(int val) { r = val; }
        int GetGreen() { return g; }
        void SetGreen(int val) { g = val; }
        int GetBlue() { return b; }
        void SetBlue(int val) { b = val; }
        int GetAlpha() { return a; }
        void SetAlpha(int val) { a = val; }
        void SetColour(int red, int green, int blue, int alpha) {
            r = red;
            g = green;
            b = blue;
            a = alpha;
        }

        friend class DrawHelper;
    };
}
