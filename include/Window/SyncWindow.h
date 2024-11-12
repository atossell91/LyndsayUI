#pragma once

#include "Window/IWindow.h"
#include "Window/WindowBase.h"
#include "Window/WindowFactory.h"

namespace LyndsayUI {
    class SyncWindow : public WindowBase {
    private:
        //  Private stuff here
        int windowId;
        std::unique_ptr<IWindow> platformWindow;
        SyncWindow(int id, std::unique_ptr<IEventTent> evTent) : WindowBase(id, std::move(evTent)) {}

        
        //  Event Dispatcher

        friend std::unique_ptr<IWindow> WindowFactory::CreateSynchronousWindow();
    public:
        //  Public stuff here
    };
} // LyndsayUI
