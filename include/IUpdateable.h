#pragma once

namespace LyndsayUI {
    class IUpdateable {
    public:
        virtual ~IUpdateable() {}
        virtual void Update() = 0;
    };
}
