#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Physics/Force/ForceGenerator.h"
#include <glm/vec3.hpp>


namespace Tower
{
    class AnchoredSpring: public ForceGenerator
    {
    public:
        AnchoredSpring(void);

        AnchoredSpring(const glm::vec3& anchor, real springConstant, real restLength);

        ~AnchoredSpring(void);

        void v_UpdateForce(p_RigidBody2D body) final;

        void v_UpdateForce(p_RigidBody3D body) final;

        void SetAnchor(const glm::vec3& anchor);

        void SetSpringConstant(real constant);

        void SetRestLength(real length);

    private:
        glm::vec3 _anchor;
        real _springConstant;
        real _restLength;
    };//end AnchoredSpring
    typedef shared_ptr<AnchoredSpring> p_AnchoredSpring;
}//end Namespace