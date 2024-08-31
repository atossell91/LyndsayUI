#pragma once

#include <vector>

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../include/DrawableBase.h"

namespace RixinSDL
{
    class spiral : public DrawableBase {
    private:
        float animRot = 0.0f;

        std::vector<float> vertexNums;
        float spiralWidth = 0;
        float spiralHeight = 0;

        float calcRad(float angle);
        glm::vec2 calcVector(float angle, float rad);
        void calculate();

    public:
        float getWidth() const { return spiralWidth; }
        float getHeight() const { return spiralHeight; }

        spiral(GLuint shaderProgramRef);
        void draw();
    };
} // namespace RixinSDL
