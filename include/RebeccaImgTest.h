#pragma once

#include <glad/glad.h>

#include "BufferedImage.h"
#include "../include/DrawableBase.h"

namespace RebeccaUI {
    class RebeccaImgTest : public DrawableBase {

    private:
        BufferedImage image;

        public:

        RebeccaImgTest(BufferedImage image, GLuint shaderProgramRef);
        void draw();

        static const int vertexArrayElems = 36;
        static const int elementIndices = 6;

        // Not static - Consider making this static
        const float vertices[vertexArrayElems] = {
            -1.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,     0.0f, 0.0f, // Bottom Left (Origin)
            1.0f, -1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,     1.0f, 0.0f, // Bottom Right
            1.0f, 1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,     1.0f, 1.0f, // Top Right
            -1.0f, 1.0f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,     0.0f, 1.0f, // Top Left
        };

        const int indices[elementIndices] = {0, 1, 2, 2, 3, 0};
    };
}