#pragma once

#include <memory>

#include "IRebeccaWindow.h"
#include "Event/EventTent.h"

namespace LyndsayUI {
    class WindowBase : public IRebeccaWindow {
    private:
        //  Private stuff here
        int windowId;
        std::unique_ptr<IEventTent> eventTent;
    protected:
        WindowBase(int winId, std::unique_ptr<IEventTent> evTent) : windowId{winId}, eventTent{std::move(evTent)} {}
    public:
        //  Public stuff here
        int GetWindowId() { return windowId; }
        void RecieveEvent(std::unique_ptr<IEvent> event) { eventTent->RecieveEvent(std::move(event)); }
    };
} // LyndsayUI
