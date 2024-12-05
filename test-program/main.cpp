#include <iostream>

#include "LyndsayUI.h"
#include "ILyndsayDependencyFactory.h"
#include "SDLLyndsayDependencyFactory.h"

#include <SDL3/SDL.h>
#include <thread>
#include <chrono>

#include "Custom/MckaylaWindow.h"

int main() {

    auto factory = std::make_unique<NSLyndsayUI::SDLLyndsayDependencyFactory>();
    NSLyndsayUI::LyndsayUI lyndsay(factory.get());

    auto win = lyndsay.CreateWindow<NSLyndsayUI::MckaylaWindow>();
    win->Close();
    //lyndsay.Run();
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
    std::cout << "Done - it didn't segfault this time (at least not yet)" << std::endl;
}
