#include "../include/Window.h"

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

#include <SDL3_image/SDL_image.h>

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glad/glad.h"
#include "../include/ShaderUtils.h"
#include "../include/Utilities.h"
#include "../include/BufferedImage.h"
#include "../include/mckayla.h"
#include "../include/spiral.h"

void RixinSDL::Window::init() {
    SDL_GL_MakeCurrent(window, glContext);

    // Seems to require a glContext, otherwise it segfaults
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
    
    glViewport(0, 0, width, height);
}

void RixinSDL::Window::windowLoop() {
    while(windowRunning) {
        SDL_GL_MakeCurrent(window, glContext);

        glClearColor(1.0, 0.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        drawManager.drawAll();
        update();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void RixinSDL::Window::update() {
    SDL_GL_SwapWindow(window);
}

RixinSDL::Window::~Window() {
    SDL_DestroyWindow(window);
    //SDL_GL_DestroyContext(glContext);
}

void RixinSDL::Window::stopLoop() {
    windowRunning = false;
}

RixinSDL::BufferedImage RixinSDL::Window::bufferImage(const std::string& imgPath) {
    SDL_GL_MakeCurrent(window, glContext);
    
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
    
    auto deets = SDL_GetPixelFormatDetails(sfc->format);
    
    int bytesPerPixel = SDL_BYTESPERPIXEL(sfc->format);

    std::cout << "Bytes per pixel: " << bytesPerPixel << std::endl;

    int type = bytesPerPixel > 3 ? GL_RGBA : GL_RGB;

    glTexImage2D(GL_TEXTURE_2D, 0, type, sfc->w, sfc->h, 0, type, GL_UNSIGNED_BYTE, sfc->pixels);
    std::cout << "Applied the Texture" << std::endl;

    RixinSDL::BufferedImage ref(tex, sfc->w, sfc->h);
    SDL_DestroySurface(sfc);
    return ref;
}
