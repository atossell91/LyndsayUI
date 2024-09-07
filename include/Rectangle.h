#pragma once

namespace RixinSDL {
    class Rectangle {
    private:
        //  Private stuff here
        float x;
        float y;
        float w;
        float h;
    public:
        //  Public stuff here
        Rectangle(float x, float y, float w, float h) : 
            x{x}, y{y}, w{w}, h{h} {}

        float getX() const  { return x; }
        void setX(float val) { x = val; }

        float getY() const  { return y; }
        void setY(float val) { y = val; }

        float getW() const  { return w; }
        void setW(float val) { w = val; }

        float getH() const  { return h; }
        void setH(float val) { h = val; }

    };
} // RixinSDL
