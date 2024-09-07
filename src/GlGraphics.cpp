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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
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
            "/home/ant/Programming/RixinSDL/shaders/fragment-notex.glsl"
        );
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

std::vector<float> GlGraphics::calcArcVertices(
    float startAngle, float arcAngle,
    float innerRadStart, float innerRadEnd,
    float outerRadStart, float outerRadEnd) {
    std::vector<float> data;

    float turnAmt = 1.0f;

    float innerIncrease = (innerRadEnd - innerRadStart)/((arcAngle/turnAmt));
    float outerIncrease = (outerRadEnd - outerRadStart)/((arcAngle/turnAmt));

    float innerRad = innerRadStart;
    float outerRad = outerRadStart;
    
    for (float angle = startAngle; angle < (arcAngle + turnAmt); angle += turnAmt) {
        float rAngle = glm::radians(angle);

        float x = 0.0f;
        float y = 0.0f;

        data.push_back(glm::cos(rAngle) * (innerRad + innerIncrease*angle));
        data.push_back(glm::sin(rAngle) * (innerRad + innerIncrease*angle));
        data.push_back(0.0f);

        data.push_back(glm::cos(rAngle) * (outerRad + outerIncrease*angle));
        data.push_back(glm::sin(rAngle) * (outerRad + outerIncrease*angle));
        data.push_back(0.0f);
    }
    return data;
}

void GlGraphics::DrawSpiral(const TransformParams& params) {
    // Calculate the vertices

    if (spiralVao < 0) {

        // This should be it's own function in it's own class

        float r1 = 0.0;
        float width = 0.1f;
        float spins = 10;
        float space = 0.05f;
        float increase = width*2*spins;
        auto data = calcArcVertices(360.0f * 0, 360*spins, r1, increase, r1, increase + width);
        numSpiralData = data.size();
        spiralVao = bufferPrimitive(&data[0], numSpiralData);
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
    glUniform3f(uColour, 0.25f, 0.5f, 1.0f);

    glEnable(GL_PROGRAM_POINT_SIZE);
    glPointSize(2);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, numSpiralData/3);
    
    // Shove the vertices into a glBuffer
    // Draw the buffer
}

void GlGraphics::Clear() {
    glClearColor(0.4f, 0.7f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);;
}
