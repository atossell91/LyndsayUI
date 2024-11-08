#pragma once

#include "Window/IWindow.h"
#include "Window/WindowFactory.h"

namespace RebeccaUI {
    class SyncWindow : public IWindow {
    private:
        //  Private stuff here
        int windowId;
        std::unique_ptr<IWindow> platformWindow;
        SyncWindow(int id, std::unique_ptr<IWindow> window) : windowId{id}, platformWindow{std::move(window)} {}

        //  Event Dispatcher

        friend std::unique_ptr<IWindow> WindowFactory::CreateSynchronousWindow();
    public:
        //  Public stuff here
    };
} // RebeccaUI
