#include "../include/mckayla.h"

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

using namespace RixinSDL;

Mckayla::Mckayla(RixinSDL::BufferedImage image, GLuint shaderProgramRef) : DrawableBase(shaderProgramRef), image{image} {

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

void Mckayla::draw() {
    std::cout << "Start draw" << std::endl;
    
    if (shaderID >= 0) {
    std::cout << "Start draw" << std::endl;
        // Prepare the matrix
        auto transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(xTranslate, yTranslate, 0.0f));
        transform = glm::scale(transform, glm::vec3(xScale, yScale, 1.0f));
        transform = glm::rotate(transform, glm::radians(zRotation), glm::vec3(0.0f, 0.0f, 1.0f));


        std::cout << "Setting the program" << std::endl;
        glUseProgram(shaderID);

        std::cout << "Setting the matrix uniform" << std::endl;
        GLuint tMatrixLoc = glGetUniformLocation(shaderID, "Transform");
        glUniformMatrix4fv(tMatrixLoc, 1, GL_FALSE, glm::value_ptr(transform));
    }

    if (image.getBufferId() >= 0) {
        std::cout << "Binding the image" << std::endl;
        glBindTexture(GL_TEXTURE_2D, image.getBufferId());
    }

    std::cout << "Start draw" << std::endl;
    glBindVertexArray(vao);

    std::cout << "Actually doing the drawing now" << std::endl;
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    std::cout << "Leaving draw" << std::endl;
}
