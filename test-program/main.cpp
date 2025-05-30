#include <iostream>
#include <filesystem>

#include "LyndsayUI.h"
#include "MyWin.h"

#include "LinuxSpecificFunctions.h"

int main() {

    NSLyndsayUI::LyndsayUI lyndsay;
    lyndsay.AddWindow<NSLyndsayUI::MyWin>();
    lyndsay.RunImmediate();

    auto p = std::filesystem::path("/home/ant");
    std::cout << "Done - it didn't segfault this time (at least not yet)" << std::endl;

    NSLyndsayUI::LinuxSpecificFunctions funcs;
    std::cout << funcs.GetBinaryPath() << std::endl;
}
