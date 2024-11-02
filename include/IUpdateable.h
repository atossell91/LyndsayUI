#pragma once

namespace RixinSDL {
    class IUpdateable {
    public:
        virtual ~IUpdateable() {}
        virtual void Update() = 0;
    };
}
