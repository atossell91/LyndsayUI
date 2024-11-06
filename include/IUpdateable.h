#pragma once

namespace RebeccaUI {
    class IUpdateable {
    public:
        virtual ~IUpdateable() {}
        virtual void Update() = 0;
    };
}
