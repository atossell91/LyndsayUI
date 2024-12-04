#pragma once

#include <vector>
#include <memory>

#include "IDrawable.h"

namespace NSLyndsayUI {
    class DrawableCollection {
    private:
        using d_ptr = std::shared_ptr<IDrawable>;

        struct CollectionElement {
            d_ptr Drawable;
            int collectionId = 0;
        };

        //  Private stuff here
        int nextId = 1;

        std::vector<CollectionElement> drawables;

        CollectionElement createElement(d_ptr drawable) {
            CollectionElement elem;
            elem.collectionId = nextId;
            elem.Drawable = drawable;

            ++nextId;

            return elem;
        }
    public:
        //  Public stuff here
        int AddDrawableToEnd(d_ptr drawable) {
            CollectionElement elem = createElement(drawable);
            drawables.push_back(elem);
            return elem.collectionId;
        }

        int AddDrawableAt(int index, d_ptr drawable) {
            if (index < 0) return -1;

            std::vector<CollectionElement>::iterator iter = drawables.begin();
            for (int n =0; n < index && iter != drawables.end(); ++n) {
                iter = std::next(iter);
            }

            //  If n > vector size, this 'should' add to the end. Look here if 
            //    it starts segfaulting
            CollectionElement elem = createElement(drawable);
            drawables.insert(iter, elem);
            return elem.collectionId;
        }

        void RemoveDrawable(int id) {
            for (auto iter = drawables.begin(); iter != drawables.end(); iter = std::next(iter)) {
                if (iter->collectionId == id) {
                    drawables.erase(iter);
                    break;
                }
            }
        }

        void DrawAll(IGraphics* graphics) {
            for (auto& drawable : drawables) {
                drawable.Drawable->Draw(graphics);
            }
        }
    };
} // LyndsayUI
