#pragma once

#include "Window/IWindow.h"
#include "Window/WindowBase.h"
#include "Window/WindowFactory.h"

namespace RebeccaUI {
    class SyncWindow : public WindowBase {
    private:
        //  Private stuff here
        int windowId;
        std::unique_ptr<IWindow> platformWindow;
        SyncWindow(int id) : WindowBase(id) {}

        //  Event Dispatcher

        friend std::unique_ptr<IWindow> WindowFactory::CreateSynchronousWindow();
    public:
        //  Public stuff here
    };
} // RebeccaUI
