#pragma once

#include <memory>

namespace LyndsayUI {
    namespace Utils {
        template <typename F, typename T>
        std::unique_ptr<T> CastUniquePtr(std::unique_ptr<F> ptr) {
            auto p = std::unique_ptr<T>(static_cast<T*>(ptr.release()));
            return std::move(p);
        }
    }
} // LyndsayUI
