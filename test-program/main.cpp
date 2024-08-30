#include <iostream>
#include "RixinSDL.h"

int main() {
    RixinSDL::RixinSDL rsdl;

    rsdl.Run();
    std::cout << "Done!" << std::endl;
    return 0;
}
