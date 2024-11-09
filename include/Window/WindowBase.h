#pragma once

#include <memory>

#include "Window/IWindow.h"
#include "Event/IEventReceiver.h"
#include "Event/EventTent.h"

namespace RebeccaUI {
    class WindowBase : public IWindow, public IEventReceiver {
    private:
        //  Private stuff here
        int windowId;
        std::unique_ptr<IEventTent> eventTent;
    protected:
        WindowBase(int winId, std::unique_ptr<IEventTent> evTent) : windowId{winId}, eventTent{std::move(evTent)} {}
    public:
        //  Public stuff here
        int GetWindowId() { return windowId; }
        void RecieveEvent(std::unique_ptr<IEvent> event);
    };
} // RebeccaUI
