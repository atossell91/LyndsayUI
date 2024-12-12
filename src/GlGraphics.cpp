#include "Drawing/GlGraphics.h"

#include <iostream>

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <SDL3_image/SDL_image.h>

#include "glad/glad.h"
#include "ShaderUtils.h"
#include "Drawing/BufferedImage.h"
#include "Utilities.h"

using namespace NSLyndsayUI;

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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    return vao;
}

void GlGraphics::applyShaders(GLuint targetProgram) {

}

void GlGraphics::applyTransforms(GLuint shaderProg, const TransformParams& params) {
    
    GLuint uTransform = glGetUniformLocation(shaderProg, TransformUniform);
    // Setup the transform matrix, and set it as the uniform
    auto transform = glm::mat4(1.0f);
    transform = glm::translate(transform, glm::vec3(
        params.getXtranslation(),
        params.getYtranslation(),
        params.getZtranslation()
        )
    );

    // The first scale accounts for the aspect ratio of the screen - The second is the user defined scale
    transform = glm::scale(transform, glm::vec3(1.0f*(1080.0f/1920.0f), 1.0f, 1.0f));
    transform = glm::scale(transform, glm::vec3(
        params.getXscale(),
        params.getYscale(),
        params.getZscale()
    ));
    
    transform = glm::rotate(transform, glm::radians(params.getZrotation()), glm::vec3(0.0f, 0.0f, 1.0f));

    glUniformMatrix4fv(uTransform, 1, GL_FALSE, glm::value_ptr(transform));
    
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
            "/home/ant/Programming/LyndsayUI/shaders/vertex-notex.glsl",
            "/home/ant/Programming/LyndsayUI/shaders/fragment-notex.glsl"
        );
    }
    glUseProgram(solidShader);

    applyTransforms(solidShader, params);

    GLuint uColour = glGetUniformLocation(solidShader, "Colour");
    glUniform4f(uColour, 1.0f, 0.0f, 0.0f, 0.5);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, numQuadPoints/5);
}

NSLyndsayUI::BufferedImage GlGraphics::BufferImage(const std::string& imgPath) {
    SDL_GL_MakeCurrent(window, glContext);
    
    SDL_Surface* sfc = IMG_Load(imgPath.c_str());

    if (!sfc) {
        std::cout << "Failed to load image" << std::endl;
    }

    SDL_assert(sfc);

    NSLyndsayUI::Utilities::FlipImageSurface(sfc);
    
    GLuint tex;
    glGenTextures(1, &tex);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    auto deets = SDL_GetPixelFormatDetails(sfc->format);
    
    int bytesPerPixel = SDL_BYTESPERPIXEL(sfc->format);

    int type = bytesPerPixel > 3 ? GL_RGBA : GL_RGB;

    glTexImage2D(GL_TEXTURE_2D, 0, type, sfc->w, sfc->h, 0, type, GL_UNSIGNED_BYTE, sfc->pixels);

    NSLyndsayUI::BufferedImage ref(tex, sfc->w, sfc->h);
    SDL_DestroySurface(sfc);
    return ref;
}

void GlGraphics::DrawImage(BufferedImage image, 
            const Rectangle& sourceRect, const Rectangle& destRect, const TransformParams& params) {
    SDL_GL_MakeCurrent(window, glContext);

    // Use the image shader program
    if (imgShader < 0) {
        imgShader = ShaderUtils::BuildShaderProgram(
            "/home/ant/Programming/LyndsayUI/shaders/vertex-tex.glsl",
            "/home/ant/Programming/LyndsayUI/shaders/fragment-tex.glsl");
    }
    glUseProgram(imgShader);
    
    applyTransforms(imgShader, params);

    // Use the buffered image (bind it?)
    glBindTexture(GL_TEXTURE_2D, image.getBufferId());

    // Set and transform the destination recatange (quad)
    if (quadVao < 0) {
        quadVao = bufferPrimitive(quadVertices, numQuadPoints);
    }
    glBindVertexArray(quadVao);

    // Draw the buffer(s)
    glDrawArrays(GL_TRIANGLE_STRIP, 0, numQuadPoints/5);
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
        data.push_back(0.0f);
        data.push_back(0.0f);

        data.push_back(glm::cos(rAngle) * (outerRad + outerIncrease*angle));
        data.push_back(glm::sin(rAngle) * (outerRad + outerIncrease*angle));
        data.push_back(0.0f);
        data.push_back(0.0f);
        data.push_back(0.0f);
    }
    return data;
}

void GlGraphics::DrawSpiral(const TransformParams& params) {
    // Calculate the vertices

    if (spiralVao < 0) {

        // This should be it's own function in it's own class

        auto data = calcArcVertices(0.0f, 360*8, 0.0, 2.9, 0.0, 3);
        numSpiralData = data.size();
        spiralVao = bufferPrimitive(&data[0], numSpiralData);
    }
    glBindVertexArray(spiralVao);

    // This is duplicated code
    // Draw the buffer
    if (solidShader < 0) {
        solidShader = ShaderUtils::BuildShaderProgram(
            "/home/ant/Programming/LyndsayUI/shaders/vertex-notex.glsl",
            "/home/ant/Programming/LyndsayUI/shaders/fragment-notex.glsl");
    }
    glUseProgram(solidShader);
    
    applyTransforms(solidShader, params);

    GLuint uColour = glGetUniformLocation(solidShader, "Colour");
    glUniform4f(uColour, 1.0f, 0.4f, 0.8f, 1.0f);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

    glDrawArrays(GL_TRIANGLE_STRIP, 0, numSpiralData/5);
    
    // Shove the vertices into a glBuffer
    // Draw the buffer
}

void GlGraphics::Clear() {
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    glClearColor(0.0f, 0.15f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);;
}
