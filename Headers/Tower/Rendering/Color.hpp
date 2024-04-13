#pragma once

#include "pch.h"
#include "Tower/framework.h"

namespace Tower
{
    struct Color
    {
        F32 red;
        F32 green;
        F32 blue;

        Color(F32 r, F32 g, F32 b) : red(r), green(g), blue(g) { }
    };
}