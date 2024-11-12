#pragma once

namespace LyndsayUI {
    class IMappableIndexResolver {
    public:
        virtual ~IMappableIndexResolver() {}
        //  Public stuff here
        virtual void MapIndices(int leftIndex, int rightIndex) = 0;
    };
} // LyndsayUI
