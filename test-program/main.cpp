#include <iostream>
#include "RebeccaUI.h"
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
    RebeccaUI::RebeccaUI rsdl;
    //RebeccaUI::BufferedImage img = bufferImage("/home/ant/Downloads/RebeccaImgTest-fangirl.jpg");
    
    rsdl.GetWindowManager()->AddSingleWindow();
    RebeccaUI::Window* win = rsdl.GetWindowManager()->GetWindow();
    if (!win) {
        std::cout << "No windows" << std::endl;
    }

    RebeccaUI::DrawFunc fun;
    fun.DrawFunction = [](RebeccaUI::IGraphics* g) {
        RebeccaUI::TransformParams elaine;
        g->DrawRectangle(elaine);
    };

    //RebeccaUI::RebeccaImgTest mm()
    //window->AddDrawable()

    //imgRef ref = imgPromise.await();
    //win->LudoVica();
    
    // Segfaults if Run() is not called
    rsdl.Run();

    std::cout << "Done!" << std::endl;
    return 0;
}
