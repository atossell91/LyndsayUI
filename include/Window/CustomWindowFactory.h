#pragma once

#include <type_traits>

#include "Window/CustomWindowBase.h"

namespace NSLyndsayUI {
    class CustomWindowFactory {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        template <typename T, std::enable_if_t<std::is_base_of<CustomWindowBase, T>::value>>
        T CreateAsycnchronousWindow() {
            
        }

        template <typename T, std::enable_if_t<std::is_base_of<CustomWindowBase, T>::value>>
        T CreateSynchronousWindow() {

        }
    };
} // NSLyndsayUI
