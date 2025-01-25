#pragma once

#include <cmath>
#include <iostream>

namespace NSLyndsayUI {

    class Line;

    class Vector2D {
    private:
    public:
    //  Public stuff here
        float X  = 0.0f;
        float Y = 0.0f;

        Vector2D() {}
        Vector2D(float x, float y) : X{x}, Y{y} {}

        Vector2D operator+(const Vector2D& otherVector) {
            Vector2D vec;
            vec.X = this->X + otherVector.X;
            vec.Y = this->Y + otherVector.Y;

            return vec;
        }

        Vector2D operator-(const Vector2D& otherVector) {
            Vector2D vec;
            vec.X = this->X - otherVector.X;
            vec.Y = this->Y - otherVector.Y;

            return vec;
        }

        Vector2D operator*(float scalar) {
            Vector2D vec;
            vec.X = this->X * scalar;
            vec.Y = this->Y * scalar;

            return vec;
        }

        Vector2D CalcPerpendicular() {
            Vector2D vec;

            vec.X = -Y;
            vec.Y = X;

            return vec;
        }

        Vector2D CalcNormalized() {
            float lenSq = this->X * this->X + this->Y * this->Y;
            float len = std::sqrt(std::abs(lenSq));

            Vector2D vec;
            vec.X = this->X/len;
            vec.Y = this->Y/len;

            return vec;
        }

        Vector2D CalcNormalVector() {
            Vector2D normal;
            normal = CalcPerpendicular().CalcNormalized();

            return normal;
        }

        Vector2D GetNegative() {
            Vector2D neg;

            neg.X = -(this->X);
            neg.Y = -(this->Y);

            return neg;
        }
    };
} // NSLyndsayUI
