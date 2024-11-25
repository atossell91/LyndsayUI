#pragma once

#include "Event/IEvent.h"
#include "Event/EventDataBase.h"
#include "Event/EventConstants.h"

namespace LyndsayUI {
    class WindowCloseButtonClickedData : public EventDataBase {
    public:
        WindowCloseButtonClickedData() : EventDataBase(EventConstants::WindowClosedEventType)  {}
    };

    class IWindowCloseButtonClicked : public IEvent<WindowCloseButtonClickedData>  {
    public:
        virtual ~IWindowCloseButtonClicked() {}
        //  Public stuff here
    };
} // LyndsayUI
