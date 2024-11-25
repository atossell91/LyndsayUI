#pragma once

#include "Event/IEvent.h"
#include "Event/EventBase.h"
#include "Event/EventDataBase.h"
#include "Event/EventConstants.h"
#include "Event/EventTypes/IWindowCloseButtonClicked.h"

namespace LyndsayUI {
    class WindowCloseButtonClicked : public EventBase<WindowCloseButtonClickedData> {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
    };
} // LyndsayUI
