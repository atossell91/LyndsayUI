#pragma once

#include <memory>
#include <type_traits>

#include "Window/RetainedWindow.h"
#include "Window/ImmediateWindow.h"
#include "Window/CustomWindow.h"
#include "Window/IPlatformWindowFactory.h"

namespace NSLyndsayUI {
    class CustomWindowFactory {
    private:
        //  Private stuff here
        std::unique_ptr<IPlatformWindowFactory> platWinFactory;
    public:
        //  Public stuff here
        CustomWindowFactory(std::unique_ptr<IPlatformWindowFactory> platWinFactory) : platWinFactory{std::move(platWinFactory)} {}

        template <typename T, std::enable_if_t<std::is_base_of<CustomWindow, T>::value, bool> = true>
        std::unique_ptr<T> CreateImmediateWindow() {
            auto platformWindow = platWinFactory->CreateWindow();
            auto win = std::make_unique<T>();
            win->platformWindow.reset(platformWindow.release());

            win->Setup();

            return std::move(win);
        }

        //template <typename T, std::enable_if_t<std::is_base_of<RetainedWindow, T>::value>>
        //std::unique_ptr<T> CreateRetainedWindow() {}
    };
} // NSLyndsayUI
