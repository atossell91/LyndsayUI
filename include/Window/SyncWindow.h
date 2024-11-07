#pragma once

#include "Window/IWindow.h"
#include "Window/WindowFactory.h"

namespace RebeccaUI {
    class SyncWindow {
    private:
        //  Private stuff here
        int windowId;
        SyncWindow(int id) : windowId{id} {}

        //  Event Dispatcher

        friend std::unique_ptr<IWindow> WindowFactory::CreateSynchronousWindow();
    public:
        //  Public stuff here
    };
} // RebeccaUI
