#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec2.hpp>

namespace Tower
{
    struct CharacterData
    {
        U32 TextureId;
        glm::ivec2 Size;
        glm::ivec2 Bearing;
        U32 Advance;
    };
}