#pragma once

namespace NSLyndsayUI {
    class IIndexResolver {
    public:
        virtual ~IIndexResolver() {}
        //  Public stuff here
        virtual int ResolveIndex(int index) = 0;
    };
} // LyndsayUI
