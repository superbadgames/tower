#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec2.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>

namespace Tower
{
    struct Character
    {
        U32 TextureId;
        glm::ivec2 Size;
        glm::ivec2 Bearing;
        U32 Advance;
    };

    class Font
    {
    public:
        Font(void);

        ~Font(void);

        // A width of 0 will allow the width to dynamically scaled with the height
        void Load(const string& filepath, U32 height, U32 width = 0);

    private:
        std::map<char, Character> _characters;
    };
    typedef shared_ptr<Font> p_Font;
}