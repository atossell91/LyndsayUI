#pragma once

namespace NSLyndsayUI {
    class IMappableIndexResolver {
    public:
        virtual ~IMappableIndexResolver() {}
        //  Public stuff here
        virtual void MapIndices(int leftIndex, int rightIndex) = 0;
    };
} // LyndsayUI
