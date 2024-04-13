#pragma once

//=====Engine includes=====
#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Force/ForceGenerator.h"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>


namespace Tower
{
    class GravityForce: public ForceGenerator
    {
    public:
        GravityForce(void);

        GravityForce(const glm::vec3& gravity);

        ~GravityForce(void);

        void v_UpdateForce(p_RigidBody2D body) final;

        void v_UpdateForce(p_RigidBody3D body) final;

        inline void Set(const glm::vec3& gravity)
        {
            // _gravityAcc = gravity;
        }


    private:
        glm::vec3 _gravityAcc;
    };//end class
    typedef shared_ptr<GravityForce> p_GravityForce;
}//end namespace