#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Texture.hpp"
#include <glm/vec2.hpp>

namespace Tower
{
    struct CharacterData
    {
        p_Texture texture;
        glm::ivec2 size;
        glm::ivec2 bearing;
        U32 advance;
    };
}