#pragma once

#include "Event/IEventManager.h"
#include "Event/Event.h"
#include "Event/EventData/WindowCloseButtonClickedEventData.h"

namespace NSLyndsayUI {
    class AbstractWindowEventManager : public IEventManager {
    public:
        virtual ~AbstractWindowEventManager() {}
        //  Public stuff here
        Event<WindowCloseButtonClickedEventData> WindowCloseButtonClicked;
    };
} // NSLyndsayUI
