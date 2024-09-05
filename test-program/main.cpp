#include <iostream>
#include "RixinSDL.h"

#include <SDL3_image/SDL_image.h>

#include "../include/BufferedImage.h"
#include "../include/Utilities.h"
#include "../include/ShaderUtils.h"
#include "Window.h"

#include "../include/mckayla.h"

int main() {
    RixinSDL::RixinSDL rsdl;
    //RixinSDL::BufferedImage img = bufferImage("/home/ant/Downloads/mckayla-fangirl.jpg");
    
    RixinSDL::Window* win = rsdl.GetWindowManager().GetWindow();
    if (!win) {
        std::cout << "No win" << std::endl;
    }

    RixinSDL::Window* window = rsdl.GetWindowManager().GetWindow();

    EmilyPromise::Promise<RixinSDL::BufferedImage> promise;
    window->AddImageToBuffer("/home/ant/Downloads/mckayla-smile.jpg", promise);
    auto buf = promise.wait();
    std::cout << "ID: " << buf.getBufferId() << std::endl;

    //RixinSDL::Mckayla mm()
    //window->AddDrawable()

    //imgRef ref = imgPromise.await();
    //win->LudoVica();
    
    // Segfaults if Run() is not called
    rsdl.Run();

    std::cout << "Done!" << std::endl;
    return 0;
}
