#include <iostream>
#include "RixinSDL.h"
#include <functional>
#include <SDL3_image/SDL_image.h>

#include "Drawing/TransformParams.h"
#include "Drawing/IGraphics.h"
#include "Drawing/DrawFunc.h"
#include "Drawing/BufferedImage.h"
#include "Utilities.h"
#include "../include/ShaderUtils.h"
#include "Drawing/DrawableCollection.h"
#include "Window/Window.h"

int main() {
    RixinSDL::RixinSDL rsdl;
    //RixinSDL::BufferedImage img = bufferImage("/home/ant/Downloads/mckayla-fangirl.jpg");
    
    rsdl.GetWindowManager()->AddSingleWindow();
    RixinSDL::Window* win = rsdl.GetWindowManager()->GetWindow();
    if (!win) {
        std::cout << "No windows" << std::endl;
    }

    RixinSDL::DrawFunc fun;
    fun.DrawFunction = [](RixinSDL::IGraphics* g) {
        RixinSDL::TransformParams elaine;
        g->DrawRectangle(elaine);
    };

    //RixinSDL::Mckayla mm()
    //window->AddDrawable()

    //imgRef ref = imgPromise.await();
    //win->LudoVica();
    
    // Segfaults if Run() is not called
    rsdl.Run();

    std::cout << "Done!" << std::endl;
    return 0;
}
