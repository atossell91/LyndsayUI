#include "../include/WindowStuff/Window.h"

#include <iostream>
#include <vector>

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

    glClearColor(1.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, width, height);
}

void RixinSDL::Window::update() {
    std::cout << "Updating" << std::endl;
    SDL_GL_SwapWindow(window);
}
