/*

A Particle is the simplest object that can be simulated in the physics engine.

*/

#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Entity.hpp"
#include <glm/vec3.hpp>

namespace Tower
{
    class Particle
    {
    public:
        Particle(void);

        Particle(p_Entity entity);

        ~Particle(void);

        inline void SetEntity(p_Entity entity) { _entity = entity; }

        void SetMass(F32 mass);

        inline void SetInverseMass(F32 inverse) { _inverseMass = inverse; }

        inline void SetDamping(F32 damping) { _damping = damping; }

        void Integrate(F32 delta);

    private:
        p_Entity _entity;
        glm::vec3 _velocity;
        glm::vec3 _acceleration;
        // 0.0 = 100% drag, no velocity after integration
        // 1.0f = no drag. Maybe 0.999 is better for the math
        F32 _damping;
        // Inverse to simplify math in the integrator.
        // An inverse mass of 0.0 implies an infinite mass,
        // thus acceleration will have no effect on the initial velocity
        F32 _inverseMass;

        void _ClearForceAccumulators(void);
    };
    typedef shared_ptr<Particle> p_Particle;
}