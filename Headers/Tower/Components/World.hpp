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

        virtual void v_Init(void) = 0;

        virtual void v_Update(void) = 0;

        virtual void v_Render(void) = 0;

    protected:
    };
    typedef shared_ptr<World> p_World;
}