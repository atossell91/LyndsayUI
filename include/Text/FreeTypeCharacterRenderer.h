#pragma once

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

//#include <freetype2/freetype/freetype.h>
#include <cstdlib>

#include "ICharacterRenderer.h"
#include "ImageData.h"
#include "LyndsayGlyph.h"

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
            FT_New_Face(ft, "/home/ant/programming/LyndsayUI/fonts/Roboto-VariableFont_wdth,wght.ttf", 0, &face);
        }

        void SetFontHeight(int fontHeight) { FT_Set_Pixel_Sizes(face, 0, fontHeight); }

        void GetGlyph(char character) {
            // What happens if this fails?
            FT_Load_Char(face, character, FT_LOAD_RENDER);

            LyndsayGlyph glyph;
            ImageData data;
            
            // Pitch can be negative & sign denotes order of rows in the bitmap
            size_t absPitch = 0;
            if (face->glyph->bitmap.pitch >= 0) {
                absPitch = static_cast<size_t>(face->glyph->bitmap.pitch);
                data.RowOrder = ImageRowOrder::TopToBottom;
            }
            else {
                absPitch = static_cast<size_t>(-face->glyph->bitmap.pitch);
                data.RowOrder = ImageRowOrder::BottomToTop;
            }

            data.RowCount = face->glyph->bitmap.rows;
            data.ImageWidth = face->glyph->bitmap.width;
            data.RowWidth = absPitch;
            
            size_t count = face->glyph->bitmap.rows * absPitch;

            // Transfer the glyph data
            data.Buffer.reserve(count);
            int bufferIndex = 0;
            for (size_t row=0; row < face->glyph->bitmap.rows; ++row) {
                for (size_t col=0; col < absPitch; ++col) {
                    // Transfer
                    bufferIndex = absPitch * row + col;
                    data.Buffer[bufferIndex] = face->glyph->bitmap.buffer[bufferIndex];
                }
            }

            // Is this only ever single?
            data.ColourType = PixelColourType::Single;

            glyph.data = data;
            glyph.Width = data.ImageWidth;
            glyph.Height = data.RowCount;
            glyph.BearingX = face->glyph->bitmap_left;
            glyph.BearingY = face->glyph->bitmap_top;
            glyph.Advance = face->glyph->advance.x;
        }
    };
} // NSLyndsayUI
