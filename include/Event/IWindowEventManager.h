#pragma once

#include "Event/IEventManager.h"

namespace NSLyndsayUI {
    enum EventMode {
        Constant = 0,
        Patient = 1
    };

    class IWindowEventManager : public IEventManager {
    public:    
        virtual ~IWindowEventManager() {}
        //  Public stuff here
        virtual void SetEventMode(EventMode mode) = 0;
    };
} // NSLyndsayUI
