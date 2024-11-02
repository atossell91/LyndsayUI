#pragma once

namespace RixinSDL {
    class IEventManager {
    public:
        virtual ~IEventManager() {}
        //  Public stuff here
        virtual void ProcessEvents() = 0;
    };
} // RixinSDL
