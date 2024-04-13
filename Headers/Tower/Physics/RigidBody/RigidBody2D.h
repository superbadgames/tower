#pragma once

#include "pch.h"
#include "Tower/framework.h"
//#include "Math/Timer.h"
#include "Tower/Entity.hpp"
#include <glm/vec2.hpp>

#include <cassert>


namespace Tower
{
    class RigidBody2D
    {
    public:
        RigidBody2D(void);

        RigidBody2D(const RigidBody2D* RigidBody2D);

        RigidBody2D(const RigidBody2D& RigidBody2D);

        virtual ~RigidBody2D(void);

        void Integrate(void);

        //void UpdateVelocityAndAcceleration(const TE::SteeringOutput2D steering);

        void ClearAccumulator(void);

        void SetRotation(real euler);

        real GetRotation(void) const;

        void SetActive(bool state);

        bool GetActive(void) const;

        void SetEntity(p_Entity obj);

        p_Entity GetEntity(void) const;

        const glm::vec2 GetPosition(void) const;

        const glm::vec2& GetVelocity(void) const;

        void SetVelocity(const glm::vec2& vel);

        const glm::vec2& GetAcceleration(void) const;

        void SetAcceleration(const glm::vec2& acc);

        const glm::vec2& GetForces(void) const;

        void AddForce(const glm::vec2& force);

        void AddForceAtPoint(const glm::vec2& force, const glm::vec2 point);

        const glm::vec2& GetGravityForce(void) const;

        void SetGravityForce(const glm::vec2& grav);

        const real GetInverseMass(void) const;

        void SetInverseMass(real inverseMass);

        bool HasFiniteMass(void);

        const real GetMass(void);

        void SetMass(real mass);

        void SetMomentOfInertia(real inertia);

        real GetMomentOfInertia(void) const;

        const real GetLinearDamping(void) const;

        void SetLinearDamping(real damp);

        void SetAngularDamping(real angularDamping);

        real GetAngularDamping(void) const;

    private:
        bool _active;
        real _inverseMass;
        real _inverseMomentOfInertia;
        real _linearDamping;
        real _angularDamping;
        real _rotation;
        real _torqueAccum;
        p_Entity _obj;
        glm::vec2 _velocity;
        glm::vec2 _acceleration;
        glm::vec2 _forceAccum;
        glm::vec2 _gravityForce;

    };// end class
    typedef shared_ptr<RigidBody2D> p_RigidBody2D;
}// end namespace