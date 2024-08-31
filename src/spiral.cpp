#include "../include/spiral.h"

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

using namespace RixinSDL;

spiral::spiral(GLuint shaderProgramRef) : DrawableBase(shaderProgramRef) {
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    calculate();
    glBufferData(GL_ARRAY_BUFFER, vertexNums.size() * sizeof(float), &vertexNums[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*7, (void*)(0*sizeof(float)));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float)*7, (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
}

float spiral::calcRad(float angle) {
    return angle * 0.02;
}

glm::vec2 spiral::calcVector(float angle, float rad) {
    float x = glm::cos(angle) * rad;
    float y = glm::sin(angle) * rad;

    return glm::vec2(x, y);
}

void spiral::calculate() {
    float width = 0.01;
    for (int a = 0; a < 360*5; ++a) {
        float radAngle = glm::radians((float)a);
        auto inner = calcVector(radAngle, calcRad(radAngle) - width/2);
        vertexNums.push_back(inner[0]);
        vertexNums.push_back(inner[1]);
        vertexNums.push_back(0.0f);

        vertexNums.push_back(0.0f);
        vertexNums.push_back(0.0f);
        vertexNums.push_back(1.0f);
        vertexNums.push_back(1.0f);

        auto outer = calcVector(radAngle, calcRad(radAngle) + width/2);
        vertexNums.push_back(outer[0]);
        vertexNums.push_back(outer[1]);
        vertexNums.push_back(0.0f);

        vertexNums.push_back(0.0f);
        vertexNums.push_back(0.0f);
        vertexNums.push_back(1.0f);
        vertexNums.push_back(1.0f);

        spiralWidth = std::max(spiralWidth, outer[0]);
        spiralHeight = std::max(spiralHeight, outer[1]);
    }
}

void spiral::draw() {
        // This is duplicated from Mckayla's draw too - Can the duplication be avoided?
        if (shaderID >= 0) {
            std::cout << "Setting up the uniforms" << std::endl;
            // Prepare the matrix
            auto transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(xTranslate, yTranslate, 0.0f));
            transform = glm::scale(transform, glm::vec3(xScale, yScale, 1.0f));
            transform = glm::rotate(transform, glm::radians(zRotation), glm::vec3(0.0f, 0.0f, 1.0f));

            glUseProgram(shaderID);
            GLuint tMatrixLoc = glGetUniformLocation(shaderID, "Transform");

            glUniformMatrix4fv(tMatrixLoc, 1, GL_FALSE, glm::value_ptr(transform));
        }

        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexNums.size()/7);
}
