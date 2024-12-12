#pragma once

#include "Event/IEventManager.h"
#include "Event/Event.h"
#include "Event/EventData/WindowCloseButtonClickedEventData.h"
#include "Event/EventData/MouseMovedEventData.h"
#include "Event/EventData/MouseButtonEventData.h"
#include "Event/EventData/KeyboardEventData.h"

namespace NSLyndsayUI {
    class AbstractWindowEventManager : public IEventManager {
    public:
        virtual ~AbstractWindowEventManager() {}
        //  Public stuff here
        Event<WindowCloseButtonClickedEventData> WindowCloseButtonClicked;
        Event<MouseButtonEventData> MouseButtonDown;
        Event<MouseButtonEventData> MouseButtonUp;
        Event<MouseMovedEventData> MouseMoved;
        Event<KeyboardEventData> KeyDown;
        Event<KeyboardEventData> KeyUp;
    };
} // NSLyndsayUI
