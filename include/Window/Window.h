#pragma once

#include <memory>

#include "Window/IWindow.h"
#include "Drawing/IGraphics.h"

#include "Event/Event.h"
#include "Event/EventData/WindowCloseButtonClickedEventData.h"
#include "Event/EventData/MouseMovedEventData.h"
#include "Event/EventData/MouseButtonEventData.h"
#include "Event/EventData/KeyboardEventData.h"
#include "Event/EventData/WindowShownEventData.h"
#include "Controls/IControlCollection.h"
#include "Controls/ControlCollection.h"
#include "Window/Window.h"
#include "Event/EventData/DrawRequestedEventData.h"

namespace NSLyndsayUI {
    class Window : public IWindow {
    private:
        //  Private stuff here
        std::unique_ptr<IWindow> platformWindow;
        std::unique_ptr<IControlCollection> controls;

        void initEvents() {
            //DrawRequested.AddEventHandler([this](auto d){handleDrawRequested();});
            WindowShown.AddEventHandler([this](auto d){
                //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                handleDrawRequested();
            });
        }

        void handleDrawRequested() {
            this->RenderFrame(); // Causes a segfault if the window isn't initialized
        }
    public:
        //  Public stuff here
        Window() { initEvents(); }
        int GetWindowId() { return platformWindow->GetWindowId(); }
        
        void Close() {}

        IGraphics* GetGraphics() { 
            return platformWindow->GetGraphics();
        }

        virtual void Setup() {}
        virtual void Update() {}
        virtual void Draw() {}

        virtual void RenderFrame() {
            GetGraphics()->Clear();
            Draw();
            GetGraphics()->SwapBuffers();
        }

        Event<DrawRequestedEventData> DrawRequested;

        Event<WindowCloseButtonClickedEventData> CloseButtonPressed;
        Event<MouseButtonEventData> MouseButtonDown;
        Event<MouseButtonEventData> MouseButtonUp;
        Event<MouseMovedEventData> MouseMoved;
        Event<KeyboardEventData> KeyDown;
        Event<KeyboardEventData> KeyUp;
        Event<WindowShownEventData> WindowShown;

        friend class WindowFactory;
    };
} // NSLyndsayUI
