#pragma once

#include "Event/IWindowEventManager.h"
#include "Event/Event.h"
#include "Event/EventData/WindowCloseButtonClickedEventData.h"
#include "Event/EventData/MouseMovedEventData.h"
#include "Event/EventData/MouseButtonEventData.h"
#include "Event/EventData/KeyboardEventData.h"

namespace NSLyndsayUI {
    class AbstractWindowEventManager : public IWindowEventManager {
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
