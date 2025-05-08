#pragma once

#include <vector>
#include <memory>

#include "Controls/IControl.h"

namespace NSLyndsayUI {
    class ControlCollection {
    private:
        //  Private stuff here
        std::vector<std::unique_ptr<IControl>> controls;
    public:
        //  Public stuff here
        std::vector<std::unique_ptr<IControl>>::iterator begin() { return controls.begin();}
        std::vector<std::unique_ptr<IControl>>::iterator end() { return controls.end();}
    };
} // NSLyndsayUI
