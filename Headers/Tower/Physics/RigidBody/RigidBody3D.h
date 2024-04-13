#pragma once

#include "pch.h"
#include "Tower/framework.h"
//#include "Math/Timer.h"
#include "Tower/Entity.hpp"
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/mat4x4.hpp>

#include <cassert>

namespace Tower
{
    class RigidBody3D
    {
    public:
        RigidBody3D(void);

        ~RigidBody3D(void);

        void Integrate(void);

        void CalculateDerivedData(void);

        void SetActive(bool state);

        bool GetActive(void) const;

        const glm::vec3 GetPosition(void);

        const glm::mat4& GetInverseInertiaTensor(void) const;

        void SetInverseInertiaTensor(const glm::mat4& mat);

        const glm::vec3& GetVelocity(void) const;

        void SetVelocity(const glm::vec4& vec);

        void AddScaledVelocity(const glm::vec4& vec, F32 scale);

        const glm::vec3& GetAcceleration(void) const;

        void SetAcceleration(const glm::vec4& vec);

        void AddScaledAcceleration(const glm::vec4& vec, F32 scale);

        const glm::vec3& GetRotation(void) const;

        void SetRotation(const glm::vec3& vec);

        void AddScaledRotation(const glm::vec3& vec, F32 scale);

        const glm::vec3& GetForces(void) const;

        void AddForce(const glm::vec3& force);

        const glm::vec3& GetTorque(void) const;

        void AddTorque(const glm::vec3& torque);

        void ClearAccumulators(void);

        void AddForceAtPoint(const glm::vec3& force, const glm::vec3& point);

        real GetInverseMass(void) const;

        void SetInverseMass(real val);

        bool HasFiniteMass(void) const;

        const real GetMass(void);

        void SetMass(real mass);

        real GetLinearDamping(void) const;

        void SetLinearDamping(real val);

        real GetAngularDamping(void) const;

        void SetAngularDamping(real val);

        bool GetIsAwake(void);

        void SetEntity(p_Entity obj);

    private:
        void _TransformInertiaTensor(void);

        bool _active;
        bool _isAwake;
        real _inverseMass;
        real _linearDamping;
        real _angularDamping;
        p_Entity _obj;
        glm::mat4 _inverseInertiaTensor;
        glm::mat4 _inverseInertiaTensorInWorld;
        glm::vec3 _velocity;
        glm::vec3 _acceleration;
        glm::vec3 _rotation;
        glm::vec3 _forceAccum;
        glm::vec3 _torqueAccum;
    };//end Class
    typedef shared_ptr<RigidBody3D> p_RigidBody3D;
}//end Namespace
