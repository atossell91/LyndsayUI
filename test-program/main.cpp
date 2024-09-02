#include <iostream>
#include "RixinSDL.h"

#include <SDL3_image/SDL_image.h>

#include "../include/BufferedImage.h"
#include "../include/Utilities.h"
#include "../include/ShaderUtils.h"
#include "Window.h"

#include "../include/mckayla.h"

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

int main() {
    RixinSDL::RixinSDL rsdl;
    //RixinSDL::BufferedImage img = bufferImage("/home/ant/Downloads/mckayla-fangirl.jpg");
    
    RixinSDL::Window* win = rsdl.GetWindowManager().GetWindow();
    if (!win) {
        std::cout << "No win" << std::endl;
    }

    win->bufferImage("/home/ant/Downloads/mckayla-fangirl.jpg");
    
    /*
    int prog = RixinSDL::ShaderUtils::BuildShaderProgram(
        "/home/ant/Programming/RixinSDL/shaders/vertex.glsl",
        "/home/ant/Programming/RixinSDL/shaders/fragment-img.glsl");
    
    int progCol = RixinSDL::ShaderUtils::BuildShaderProgram(
        "/home/ant/Programming/RixinSDL/shaders/vertex.glsl", 
        "/home/ant/Programming/RixinSDL/shaders/fragment-color.glsl");
    */

    //RixinSDL::Mckayla mm(img, prog);
    
    // Segfaults if Run() is not called
    rsdl.Run();

    std::cout << "Done!" << std::endl;
    return 0;
}
