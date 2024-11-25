#include <iostream>

#include "LyndsayUI.h"
#include "ILyndsayDependencyFactory.h"
#include "SDLLyndsayDependencyFactory.h"

#include <SDL3/SDL.h>

int main() {

    //LyndsayUI::LyndsayUI lyndsay(factory.get());
    //LyndsayUI::BufferedImage img = bufferImage("/home/ant/Downloads/RebeccaImgTest-fangirl.jpg");
    
    //rsdl.GetWindowManager()->AddSingleWindow();
    //LyndsayUI::IWindow* win = rsdl.GetWindowManager()->GetWindow();
    //if (!win) {
    //    std::cout << "No windows" << std::endl;
    //}

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
    //lyndsay.Run();

    std::cout << "Done!" << std::endl;
    return 0;
}
