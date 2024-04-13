#pragma once

//=====Engine Includes=====
#include "pch.h"
#include "Tower/framework.h"
//#include "Math/Timer.h"
#include "Tower/Physics/RigidBody/RigidBody2D.h"
#include "Tower/Physics/RigidBody/RigidBody3D.h"

namespace Tower
{
    class ForceGenerator
    {
    public:
        ForceGenerator(void);

        virtual ~ForceGenerator(void);

        virtual void v_UpdateForce(p_RigidBody2D body) = 0;

        virtual void v_UpdateForce(p_RigidBody3D body) = 0;

    };//end class
    typedef shared_ptr<ForceGenerator> p_ForceGenerator;
}//end namespace
