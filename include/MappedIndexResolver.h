#pragma once

#include <map>

#include "IIndexResolver.h"
#include "IMappableIndexResolver.h"

namespace NSLyndsayUI {
    class MappedIndexResolver : public IIndexResolver, public IMappableIndexResolver {
    private:
        //  Private stuff here
        std::map<int, int> indexMap;
    public:
        //  Public stuff here
        int ResolveIndex(int index) {
            auto mapIter = indexMap.find(index);
            if (mapIter != indexMap.end()) {
                return mapIter->second;
            }

            // Figure out a different return value for this (unsuccessful find)
            return -1;
        }

        void MapIndices(int inIndex, int outIndex) {
            indexMap[inIndex] = outIndex;
        }
    };
} // LyndsayUI
