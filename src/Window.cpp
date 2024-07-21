#include "../include/WindowStuff/Window.h"

#include <iostream>

#include "glad/glad.h"

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
    SDL_GL_SwapWindow(window);
}
