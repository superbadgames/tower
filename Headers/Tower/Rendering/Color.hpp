#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec4.hpp>

namespace Tower
{
    struct Color
    {
        F32 red;
        F32 green;
        F32 blue;

        Color(void) : red(0.0f), green(0.0f), blue(0.0f) { }

        Color(F32 r, F32 g, F32 b) : red(r), green(g), blue(b) { }

        Color(const Color& color) : red(color.red), green(color.green), blue(color.blue) { }

        glm::vec4 ToVec4(void) const { return glm::vec4(red, green, blue, 1.0f); }
    };
}