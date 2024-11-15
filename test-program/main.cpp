#include <iostream>
#include "LyndsayUI.h"
#include <functional>
#include <SDL3_image/SDL_image.h>

#include "Drawing/TransformParams.h"
#include "Drawing/IGraphics.h"
#include "Drawing/DrawFunc.h"
#include "Drawing/BufferedImage.h"
#include "Utilities.h"
#include "../include/ShaderUtils.h"
#include "Drawing/DrawableCollection.h"
#include "Window/IWindow.h"

int main() {
    LyndsayUI::LyndsayUI rsdl;
    //LyndsayUI::BufferedImage img = bufferImage("/home/ant/Downloads/RebeccaImgTest-fangirl.jpg");
    
    rsdl.GetWindowManager()->AddSingleWindow();
    LyndsayUI::IWindow* win = rsdl.GetWindowManager()->GetWindow();
    if (!win) {
        std::cout << "No windows" << std::endl;
    }

    //LyndsayUI::DrawFunc fun;
    //fun.DrawFunction = [](LyndsayUI::IGraphics* g) {
    //    LyndsayUI::TransformParams elaine;
    //    g->DrawRectangle(elaine);
    //};

    //LyndsayUI::RebeccaImgTest mm()
    //window->AddDrawable()

    //imgRef ref = imgPromise.await();
    //win->LudoVica();
    
    // Segfaults if Run() is not called
    rsdl.Run();

    std::cout << "Done!" << std::endl;
    return 0;
}
