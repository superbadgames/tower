#pragma once

//=====Engine includes=====
#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Force/ForceGenerator.h"
#include "Tower/Physics/RigidBody/RigidBody2D.h"
#include "Tower/Physics/RigidBody/RigidBody3D.h"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>


namespace Tower
{
    class DragForce: public ForceGenerator
    {
    public:
        DragForce(void);

        DragForce(real drag);

        ~DragForce(void);

        void v_UpdateForce(shared_ptr<RigidBody2D> RigidBody2D) final;

        void v_UpdateForce(shared_ptr<RigidBody3D> body) final;

        inline void SetDrag(real d)
        {
            _drag = d;
            _dragSqr = _drag * _drag;
        }

        inline real GetDrag(void)
        {
            return _drag;
        }

    private:
        real _drag;
        real _dragSqr;
    };//end class
    typedef shared_ptr<DragForce> p_DragForce;
}//end namespace