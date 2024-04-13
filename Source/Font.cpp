#include "pch.h"
#include "Tower/Components/Font.hpp"
#include <iostream>

using namespace Tower;

Font::Font(void):
    _characters()
{

}

Font::~Font(void)
{

}

void Font::Load(const string& filepath, U32 height, U32 width)
{
    // Freetype will return non zero values on failure
    FT_Library ft;
    if (FT_Init_FreeType(&ft))
    {
        assert("Error! Unable to initialize freetype!");
    }

    FT_Face face;
    if (FT_New_Face(ft, filepath.c_str(), 0, &face))
    {
        string msg = "Error! Unable to load font " + filepath;
        assert(msg.c_str());
    }

    // TODO: I think this is deciding the font size. This should be a parameter.
    FT_Set_Pixel_Sizes(face, width, height);

    // Cache textures for the first 128 ASCII characters
    // Allows 1 byte aligned textures
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    for (unsigned char c = 0; c < 128; c++)
    {
        // Load character glyph
        if (FT_Load_Char(face, c, FT_LOAD_RENDER))
        {
            std::cout << "FreeType failed to load a character: " << c << std::endl;
            continue;
        }

        U32 texture;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);

        // GL_RED because we want a gray scale texture. This only pulls the r value.
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RED,
            face->glyph->bitmap.width,
            face->glyph->bitmap.rows,
            0,
            GL_RED,
            GL_UNSIGNED_BYTE,
            face->glyph->bitmap.buffer
        );

        // Set texture options
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        Character character = {
            texture,
            glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
            glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
            static_cast<U32>(face->glyph->advance.x)
        };
        _characters.insert({ c, character });
    }

    // clean up
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
}
