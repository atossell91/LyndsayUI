#pragma once

namespace RebeccaUI {
    class IMappableIndexResolver {
    public:
        virtual ~IMappableIndexResolver() {}
        //  Public stuff here
        virtual void MapIndices(int leftIndex, int rightIndex) = 0;
    };
} // RebeccaUI
