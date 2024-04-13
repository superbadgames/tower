#pragma once

//=====Engine Includes=====
#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Force/ForceGenerator.h"
#include <glm/vec4.hpp>

namespace Tower
{
    class SpringForce: public ForceGenerator
    {
    public:
        SpringForce(void);

        SpringForce(shared_ptr<RigidBody2D> otherEnd, real springConstant, real restLength);

        ~SpringForce(void);

        void v_UpdateForce(shared_ptr<RigidBody2D> RigidBody2D) final;

        void MakeBungie(bool state)
        {
            _isBungie = state;
        }

        inline void SetOtherEnd(shared_ptr<RigidBody2D> end)
        {
            _otherEnd = end;
        }

        inline void SetSpringConstant(real constant)
        {
            _springConstant = constant;
        }

        inline void SetRestLength(real length)
        {
            _restLength = length;
        }

    private:
        shared_ptr<RigidBody2D> _otherEnd;
        real _springConstant;
        real _restLength;
        bool _isBungie;

    };//end SpringForce
    typedef shared_ptr<SpringForce> p_SpringForce;
}//end Namespace