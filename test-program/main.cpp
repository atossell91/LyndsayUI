#include <iostream>

#include "LyndsayUI.h"
#include "ILyndsayDependencyFactory.h"
#include "SDLLyndsayDependencyFactory.h"

#include <SDL3/SDL.h>

int main() {

    auto factory = std::make_unique<LyndsayUI::SDLLyndsayDependencyFactory>();
    LyndsayUI::LyndsayUI lyndsay(factory.get());
    lyndsay.Run();
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
    //win->LudoVica();GetWindowManager
}
