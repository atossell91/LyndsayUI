#pragma once

#include <filesystem>

#include "IOSSpecificFunctions.h"

namespace NSLyndsayUI {
    class WindowsSpecificFunctions : public IOSSpecificFunctions {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        std::filesystem::path GetBinaryPath() const override {
        }
    };
} // NSLyndsayUI
