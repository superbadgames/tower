#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

namespace Tower
{
    struct Vertex
    {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 uvs;
    };
}