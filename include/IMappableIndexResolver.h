#pragma once

namespace RixinSDL {
    class IMappableIndexResolver {
    public:
        virtual ~IMappableIndexResolver() {}
        //  Public stuff here
        virtual void MapIndices(int leftIndex, int rightIndex) = 0;
    };
} // RixinSDL
