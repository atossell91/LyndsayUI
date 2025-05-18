#pragma once

#include <map>
#include <memory>

#include "Text/LyndsayGlyph.h"
#include "Drawing/IGraphics.h"
#include "Text/ICharacterRenderer.h"

namespace NSLyndsayUI {
    class TextManager {
    private:
        //  Private stuff here
        std::map<int, LyndsayGlyph> glyphs;

        // Doesn't own this. Be careful.
        IGraphics* renderer;

        std::unique_ptr<ICharacterRenderer> charRenderer;
    public:
        //  Public stuff here
        TextManager(IGraphics* renderer, std::unique_ptr<ICharacterRenderer> charRenderer) :
            renderer{renderer}, charRenderer{std::move(charRenderer)} {}
    };
} // NSLyndsayUI
