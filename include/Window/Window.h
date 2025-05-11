#pragma once

#include <memory>

#include "Window/CustomWindow.h"
#include "Event/EventData/DrawRequestedEventData.h"
#include "Event/Event.h"
#include "Controls/IControlCollection.h"
#include "Controls/ControlCollection.h"

namespace NSLyndsayUI {
    class Window : public CustomWindow {
    private:
        //  Private stuff here
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
        virtual void Update() {}
        virtual void Draw() {}

        virtual void RenderFrame() {
            this->GetGraphics()->Clear();
            Draw();
            this->GetGraphics()->SwapBuffers();
        }

        Window() {
            initEvents();
        }

        Event<DrawRequestedEventData> DrawRequested;

        friend class CustomWindowFactory;
    };
} // NSLyndsayUI
