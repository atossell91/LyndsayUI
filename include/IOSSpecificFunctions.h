#pragma once

#include <filesystem>

namespace NSLyndsayUI {
    class IOSSpecificFunctions {
    public:
        virtual ~IOSSpecificFunctions() {}
        //  Public stuff here
        virtual std::filesystem::path GetBinaryPath() const = 0;
    };
} // NSLyndsayUI
