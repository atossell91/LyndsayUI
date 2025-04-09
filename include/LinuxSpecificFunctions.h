#pragma once

#include <filesystem>

#include "IOSSpecificFunctions.h"

namespace NSLyndsayUI {
    class LinuxSpecificFunctions : public IOSSpecificFunctions {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        std::filesystem::path GetBinaryPath() const override {
            auto path = std::filesystem::canonical("/proc/self/exe");
            return path;
        }
    };
} // NSLyndsayUI
