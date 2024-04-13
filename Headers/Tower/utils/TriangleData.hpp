#pragma once

#include "pch.h"
#include "Tower/framework.h"

namespace Tower
{
    struct TriangleData
    {
        std::array<F32, 12> vertices{
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f, 1.0f, 0.0f
        };

        std::array<U32, 3> indices{
            1, 2, 3
        };
    };
}