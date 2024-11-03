#pragma once

namespace RixinSDL {
    class IIndexResolver {
    public:
        virtual ~IIndexResolver() {}
        //  Public stuff here
        virtual int ResolveIndex(int index) = 0;
    };
} // RixinSDL
