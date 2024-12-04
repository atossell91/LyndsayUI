#pragma once

#include "Event/IEventData.h"
#include "Event/EventBase.h"

namespace NSLyndsayUI {
    class ClickEventData : public IEventData {
    public:
    };

    class ClickEvent : public EventBase<ClickEventData> {
    private:
        //  Private stuff here
    public:
        //  Public stuff here
    };
} // roo
