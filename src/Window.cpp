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

    startLoop();
}

void RixinSDL::Window::windowLoop() {
    while(windowRunning) {
        std::cout << "Window Loop" << std::endl;
        SDL_GL_MakeCurrent(window, glContext);

        glClearColor(1.0, 0.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        drawManager.drawAll();
        update();

        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void RixinSDL::Window::startLoop() {
    thread = std::thread([this](){ windowLoop(); });
}

void RixinSDL::Window::stopLoop() {
    windowRunning = false;
    thread.join();
}

void RixinSDL::Window::update() {
    SDL_GL_SwapWindow(window);
}

RixinSDL::Window::~Window() {
    SDL_DestroyWindow(window);
    //SDL_GL_DestroyContext(glContext);
}
