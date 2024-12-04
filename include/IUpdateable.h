#pragma once

namespace NSLyndsayUI {
    class IUpdateable {
    public:
        virtual ~IUpdateable() {}
        virtual void Update() = 0;
    };
}
