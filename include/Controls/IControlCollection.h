#pragma once

#include <vector>
#include <memory>

#include "Controls/IControl.h"

namespace NSLyndsayUI {
    class IControlCollection {
    public:
        virtual ~IControlCollection() {}
        //  Public stuff here
        virtual std::vector<std::unique_ptr<IControl>>::iterator begin() = 0;
        virtual std::vector<std::unique_ptr<IControl>>::iterator end() = 0;
    };
} // NSLyndsayUI
