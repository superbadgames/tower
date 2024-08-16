#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Managers/Director.hpp"
#include <glm/mat4x4.hpp>

namespace Tower
{
    class World
    {
    public:
        World(void) {}

        virtual ~World(void) {}

        virtual void v_Init(p_Director director) = 0;

        virtual void v_Update(void) = 0;

        virtual void v_Render(const glm::mat4& viewMatrix) = 0;

    protected:
        p_Director _director;
    };
    typedef shared_ptr<World> p_World;
}