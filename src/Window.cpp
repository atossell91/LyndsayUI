#include "../include/WindowStuff/Window.h"

#include <iostream>

#include <SDL3_image/SDL_image.h>

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glad/glad.h"
#include "../include/ShaderUtils.h"
#include "../include/Utilities.h"
#include "../include/BufferedImage.h"


class Mckayla {
    private:
    GLuint vao;
    GLuint shader = -1;
    RixinSDL::BufferedImage image;

    public:
    float rotation = 0.0f;
    float xTrans = 0.0f;
    float yTrans = 0.0f;
    float xScale = 1.0f;
    float yScale = 1.0f;

    Mckayla(RixinSDL::BufferedImage image, GLuint shaderProgramRef) : image{image}, shader{shaderProgramRef} {

        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        GLuint vbo;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*9, (void*)(0*sizeof(float)));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float)*9, (void*)(3*sizeof(float)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float)*9, (void*)(7*sizeof(float)));
        glEnableVertexAttribArray(2);

        GLuint ebo;
        glGenBuffers(1, &ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

        int indices[] = {0, 1, 2, 2, 3, 0};
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    }

    void use() {
        glBindVertexArray(vao);
    }

    void draw() {
        
        if (shader >= 0) {
            // Prepare the matrix
            auto transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(xTrans, yTrans, 0.0f));
            transform = glm::rotate(transform, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
            transform = glm::scale(transform, glm::vec3(xScale, yScale, 1.0f));

            glUseProgram(shader);
            GLuint tMatrixLoc = glGetUniformLocation(shader, "Transform");

            glUniformMatrix4fv(tMatrixLoc, 1, GL_FALSE, glm::value_ptr(transform));
        }

        if (image.getBufferId() >= 0) {
            glBindTexture(GL_TEXTURE_2D, image.getBufferId());
        }

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

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

RixinSDL::BufferedImage bufferImage(const std::string& imgPath) {
        SDL_Surface* sfc = IMG_Load(imgPath.c_str());
    
        if (!sfc) {
            std::cout << "Failed to load image" << std::endl;
        }

        SDL_assert(sfc);

        RixinSDL::Utilities::FlipImageSurface(sfc);
        
        GLuint tex;
        glGenTextures(1, &tex);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, sfc->w, sfc->h, 0, GL_RGB, GL_UNSIGNED_BYTE, sfc->pixels);

        RixinSDL::BufferedImage ref(tex, sfc->w, sfc->h);
        SDL_DestroySurface(sfc);
        return ref;
}

void RixinSDL::Window::init() {
    SDL_GL_MakeCurrent(window, glContext);
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    glClearColor(1.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, width, height);

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

    RixinSDL::BufferedImage img = bufferImage("/home/ant/Downloads/mckayla-smile.jpg");
    RixinSDL::BufferedImage img2 = bufferImage("/home/ant/Downloads/mckayla-fangirl.jpg");
    int prog = RixinSDL::ShaderUtils::BuildShaderProgram("/home/ant/Programming/RixinSDL/shaders/vertex.glsl", "/home/ant/Programming/RixinSDL/shaders/fragment-img.glsl");

    glUseProgram(prog);

    // Mckayla (below) draws a rectangle in openGl, but doesn't texture it.
    Mckayla mm(img, prog);

    Mckayla mm2(img2, prog);

    // Scale to ensure the image keeps it's original size and proportions
    mm2.xScale = ((float)img2.getWidth()/ (float)width)*0.5;
    mm2.yScale = ((float)img2.getHeight() / (float)height)*0.5;
    mm2.xTrans = -0.3;

    mm.xScale = ((float)img.getWidth()/ (float)width)*0.4;
    mm.yScale = ((float)img.getHeight() / (float)height)*0.4;
    mm.xTrans = 0.2;

    mm.draw();
    mm2.draw();

    SDL_GL_SwapWindow(window);
}
