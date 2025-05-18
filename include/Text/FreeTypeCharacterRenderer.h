#pragma once

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

//#include <freetype2/freetype/freetype.h>

#include "ICharacterRenderer.h"

namespace NSLyndsayUI {
    class FreeTypeCharacterRenderer : public ICharacterRenderer {
    private:
        //  Private stuff here
        FT_Library ft;
        FT_Face face;
    public:
        //  Public stuff here
        void Init() {
            FT_Init_FreeType(&ft);
            FT_New_Face(ft, "/home/ant/Programming/LyndsayUI/fonts/Roboto-VariableFont_wdth,wght.ttf", 0, &face);
        }

        void SetFontHeight(int fontHeight) { FT_Set_Pixel_Sizes(face, 0, fontHeight); }

        void GetGlyph(char character) {
            // What happens if this fails?
            FT_Load_Char(face, character, FT_LOAD_RENDER);


        }
    };
} // NSLyndsayUI
