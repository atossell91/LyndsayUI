#pragma once

#include <vector>
#include <memory>

#include "Controls/IControl.h"
#include "Controls/IControlCollection.h"

namespace NSLyndsayUI {
    class ControlCollection : public IControlCollection {
    private:
        //  Private stuff here
        std::vector<std::unique_ptr<IControl>> controls;
    public:
        //  Public stuff here
        std::vector<std::unique_ptr<IControl>>::iterator begin() { return controls.begin(); }
        std::vector<std::unique_ptr<IControl>>::iterator end() { return controls.end(); }
    };
} // NSLyndsayUI
