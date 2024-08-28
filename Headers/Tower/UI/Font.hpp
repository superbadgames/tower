#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/UI/CharacterData.hpp"
#include "Tower/Rendering/Texture.hpp"
#include <glm/vec2.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>

namespace Tower
{


    class Font
    {
    public:
        Font(void);

        ~Font(void);

        // A width of 0 will allow the width to dynamically scaled with the height
        void Load(const string& filepath, U32 height, U32 width = 0);

        const CharacterData& GetCharacterData(char character);

    private:
        std::map<char, CharacterData> _characters;
    };
    typedef shared_ptr<Font> p_Font;
}