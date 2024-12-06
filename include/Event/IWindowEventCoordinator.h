#pragma once

#include <memory>

#include "Event/IEventProcessor.h"
#include "Event/IEventManager.h"
#include "Event/AbstractWindowEventManager.h"

namespace NSLyndsayUI {
    class IWindowEventCoordinator : public IEventProcessor {
    public:
        virtual ~IWindowEventCoordinator() {}
        //  Public stuff here
        virtual IEventManager* GetThreadEventManager() = 0;
        virtual AbstractWindowEventManager* GetPlatformEventManager() = 0;

    };
} // NSLyndsayUI
