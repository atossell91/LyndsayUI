#pragma once

#include <memory>

#include "Window/IWindow.h"
#include "Drawing/IGraphics.h"

#include "Event/Event.h"
#include "Event/EventData/WindowCloseButtonClickedEventData.h"

namespace NSLyndsayUI {
    class CustomWindow : public IWindow {
    private:
        //  Private stuff here
        std::unique_ptr<IWindow> platformWindow;
    public:
        //  Public stuff here
        int GetWindowId() { return 0; }
        void Close() {}
        IGraphics* GetGraphics() { 
            return platformWindow->GetGraphics();
        }

        virtual void Setup() {}

        Event<WindowCloseButtonClickedEventData> CloseButtonPressed;

        friend class CustomWindowFactory;
    };
} // NSLyndsayUI
