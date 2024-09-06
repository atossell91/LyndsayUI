#include "GlGraphics.h"

#include <iostream>

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glad/glad.h"
#include "ShaderUtils.h"

using namespace RixinSDL;

//  Declare functions here
void GlGraphics::initOpenGl() {
    SDL_GL_MakeCurrent(window, glContext);

    // Seems to require a glContext, otherwise it segfaults
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
}

GLuint GlGraphics::bufferPrimitive(const float vertices[], int size) {

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*size, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), 0);
    glEnableVertexAttribArray(0);

    return vao;
}

void GlGraphics::DrawRectangle(const TransformParams& params) {
    SDL_GL_MakeCurrent(window, glContext);
    // Same as spiral - ShapePrimitive class?
    // Calculate the vertices

    if (quadVao < 0) {
        quadVao = bufferPrimitive(quadVertices, numQuadPoints);
    }
    glBindVertexArray(quadVao);

    // Draw the buffer
    if (solidShader < 0) {
        solidShader = ShaderUtils::BuildShaderProgram(
            "/home/ant/Programming/RixinSDL/shaders/vertex-notex.glsl",
            "/home/ant/Programming/RixinSDL/shaders/fragment-notex.glsl");
    }
    glUseProgram(solidShader);
    
    GLuint uTransform = glGetUniformLocation(solidShader, "Transform");
    // Setup the transform matrix, and set it as the uniform
    auto transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
    transform = glm::scale(transform, glm::vec3(0.5f*(1080.0f/1920.0f), 0.5f, 1.0f));
    transform = glm::rotate(transform, glm::radians(params.rotateDegrees), glm::vec3(0.0f, 0.0f, 1.0f));

    glUniformMatrix4fv(uTransform, 1, GL_FALSE, glm::value_ptr(transform));

    GLuint uColour = glGetUniformLocation(solidShader, "Colour");
    glUniform3f(uColour, 1.0f, 0.0f, 0.0f);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, numQuadPoints);
}

void GlGraphics::DrawImage(const std::string& imgPath) {
    // Load the image
    // Shove the image into a glBuffer
    // Use the image shader program
    // Draw the buffer(s)
}

void GlGraphics::DrawString() {}

void GlGraphics::DrawLine(const TransformParams& params) {}

glm::vec2 calcPoint(float angleDeg, float rad) {
    return glm::vec2(
        glm::cos(angleDeg) * rad,
        glm::sin(angleDeg) * rad
    );
}

void GlGraphics::DrawSpiral(const TransformParams& params) {
    // Calculate the vertices

    if (spiralVao < 0) {

        // This should be it's own function in it's own class
        std::vector<float> data;
        float innerRad = 0.5;
        float outerRad = 0.6;
        float turnAmt = 1.0f;
        for (float angle = 0; angle < 360; angle += 1.0f) {
            auto innerPoint = calcPoint(angle, innerRad);
            auto outerPoint = calcPoint(angle, outerRad);
            auto nextInner = calcPoint(angle + turnAmt, innerRad);
            auto nextOuter = calcPoint(angle + turnAmt, outerRad);

            data.push_back(nextInner[0]);
            data.push_back(nextInner[1]);
            data.push_back(0.0f);
            data.push_back(innerPoint[0]);
            data.push_back(innerPoint[1]);
            data.push_back(0.0f);
            data.push_back(outerPoint[0]);
            data.push_back(outerPoint[1]);
            data.push_back(0.0f);
            data.push_back(nextOuter[0]);
            data.push_back(nextOuter[1]);
            data.push_back(0.0f);
        }

        numSpiralData = data.size();
        spiralVao = bufferPrimitive(&data[0], data.size());
    }
    glBindVertexArray(spiralVao);

    // This is duplicated code
    // Draw the buffer
    if (solidShader < 0) {
        solidShader = ShaderUtils::BuildShaderProgram(
            "/home/ant/Programming/RixinSDL/shaders/vertex-notex.glsl",
            "/home/ant/Programming/RixinSDL/shaders/fragment-notex.glsl");
    }
    glUseProgram(solidShader);
    
    GLuint uTransform = glGetUniformLocation(solidShader, "Transform");
    // Setup the transform matrix, and set it as the uniform
    auto transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(0.0f, 0.0f, 0.0f));
    transform = glm::scale(transform, glm::vec3(1.0f*(1080.0f/1920.0f), 1.0f, 1.0f));
    transform = glm::rotate(transform, glm::radians(params.xRotationDegrees), glm::vec3(1.0f, 0.0f, 0.0f));
    transform = glm::rotate(transform, glm::radians(params.rotateDegrees), glm::vec3(0.0f, 0.0f, 1.0f));

    glUniformMatrix4fv(uTransform, 1, GL_FALSE, glm::value_ptr(transform));

    GLuint uColour = glGetUniformLocation(solidShader, "Colour");
    glUniform3f(uColour, 1.0f, 0.0f, 0.0f);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, numSpiralData);
    
    // Shove the vertices into a glBuffer
    // Draw the buffer
}

void GlGraphics::Clear() {
    glClearColor(1.0f, 0.411f, 0.706f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);;
}