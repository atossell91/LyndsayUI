#include <iostream>

#include "LyndsayUI.h"
#include "MyWin.h"

int main() {

    NSLyndsayUI::LyndsayUI lyndsay;
    lyndsay.AddImmediateWindow<NSLyndsayUI::MyWin>();
    lyndsay.Run();

    std::cout << "Done - it didn't segfault this time (at least not yet)" << std::endl;
}
