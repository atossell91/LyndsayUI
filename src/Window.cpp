#include "../include/WindowStuff/Window.h"

#include <iostream>

#include <SDL3_image/SDL_image.h>

#include "glad/glad.h"
#include "../include/ShaderUtils.h"
#include "../include/Utilities.h"

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

    int prog = RixinSDL::ShaderUtils::BuildShaderProgram("/home/ant/Programming/RixinSDL/shaders/vertex.glsl", "/home/ant/Programming/RixinSDL/shaders/fragment.glsl");
    glUseProgram(prog);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    float vertices[] = {
        -0.5f, -0.5f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,     0.0f, 0.0f, // Bottom Left
        0.5f, -0.5f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,     1.0f, 0.0f, // Bottom Right
        0.5f, 0.5f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,     1.0f, 1.0f, // Top Right
        -0.5f, 0.5f, 1.0f,   1.0f, 1.0f, 1.0f, 1.0f,     0.0f, 1.0f, // Top Left
    };

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

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    SDL_Surface* sfc = IMG_Load("/home/ant/Downloads/beach.jpg");
    Utilities::FlipImageSurface(sfc);

    if (!sfc) {
        std::cout << "Failed to load image" << std::endl;
    }
    
    GLuint tex;
    glGenTextures(1, &tex);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, sfc->w, sfc->h, 0, GL_RGB, GL_UNSIGNED_BYTE, sfc->pixels);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    SDL_GL_SwapWindow(window);
}
