#pragma once

#include <list>
#include <memory>

#include "IDrawable.h"

namespace RixinSDL {
    class DrawableCollection {
    private:
        //  Private stuff here
        using d_ptr = std::unique_ptr<IDrawable>;
        std::list<d_ptr> drawables;
    public:
        //  Public stuff here
        void AddDrawableToEnd(d_ptr drawable) {
            drawables.push_back(std::move(drawable));
        }

        void AddDrawableAt(int index, d_ptr drawable) {
            if (index < 0) return;

            std::list<d_ptr>::iterator iter = drawables.begin();
            for (int n =0; n < index && iter != drawables.end(); ++n) {
                std::next(iter);
            }

            //  If n > list size, this 'should' add to the end. Look here if 
            //    it starts segfaulting
            drawables.insert(iter, drawable);
        }

        void RemoveDrawable() { 
            //drawables.erase()
        }

        void DrawAll(IGraphics* graphics) {
            for (auto& drawable : drawables) {
                drawable->Draw(graphics);
            }
        }
    };
} // RixinSDL
