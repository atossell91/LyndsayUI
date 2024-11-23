#include <iostream>

#include "LyndsayUI.h"
#include "ILyndsayDependencyFactory.h"
#include "SDLLyndsayDependencyFactory.h"

#include <SDL3/SDL.h>

int main() {
    std::unique_ptr<LyndsayUI::ILyndsayDependencyFactory> factory = std::make_unique<LyndsayUI::SDLLyndsayDependencyFactory>();
    auto evMgr = factory->CreateEventProcessor();

    SDL_UserEvent ev;
    ev.data1 = (void*)("I Love Lyndsay");
    ev.type = 1991;

    SDL_PushEvent((SDL_Event)&ev);

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
