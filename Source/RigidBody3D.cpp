#include "pch.h"
#include "Tower/Physics/RigidBody/RigidBody3D.h"
using namespace Tower;

RigidBody3D::RigidBody3D(void)
    :
    _active(true),
    _isAwake(false),
    _inverseMass(1.0f),
    _linearDamping(0.999f),
    _angularDamping(0.999f),
    _obj(nullptr),
    _inverseInertiaTensor(0.0f),
    _inverseInertiaTensorInWorld(0.0f),
    _velocity(0.0f),
    _acceleration(0.0f),
    _rotation(0.0f),
    _forceAccum(0.0f),
    _torqueAccum(0.0f)
{  }

RigidBody3D::~RigidBody3D(void)
{
    _obj = nullptr;
}

void RigidBody3D::Integrate(void)
{
    if (_obj == nullptr)
    {
        assert("RigidBody3D::Integrate: object not set!");
    }

    if (_inverseMass == 0) return;

    // TODO: Pass delta in
    //F32 delta = TM::Timer::Instance()->DeltaTime();
    // locked around 30 pfs
    F32 delta = 0.033f;

    assert(delta > 0.0f);

    glm::vec3 position = _obj->GetPosition();

    position += _velocity * delta;

    _obj->SetPosition(position);

    // TODO: Look at the book. This feels wrong.
    //_obj->SetRotationAngle(_rotation * delta);

    glm::vec3 resultingAcc = _acceleration;

    //Optional hard coded gravity should be added here

    resultingAcc += _forceAccum * delta;

    _velocity += resultingAcc * delta;
    _velocity *= real_pow(_linearDamping, delta);


    // TODO:: Something is wrong here. Check in the book
    //glm::vec3 angularAcc = _inverseInertiaTensorInWorld * _torqueAccum;

    // TODO:: same
    //_rotation = angularAcc * delta;
    //_rotation *= real_pow(_angularDamping, delta);


    CalculateDerivedData();
    ClearAccumulators();
}

void RigidBody3D::CalculateDerivedData(void)
{
    // TODO: Find another way to do this
    //_obj->NormalizeOrientation();

    // TODO:: This functionality was removed from Matrix4 and needs to be re-added
    // _inverseInertiaTensorInWorld = _obj->GetModelMatrix().Transform3x3(_inverseInertiaTensor);
}

void RigidBody3D::SetActive(bool state)
{
    _active = state;
}

bool RigidBody3D::GetActive(void) const
{
    if (_obj != nullptr)
    {
        //return _obj->GetActiveUpdate() && _active;
        return _active;
    }

    return _active;
}

const glm::mat4& RigidBody3D::GetInverseInertiaTensor(void) const
{
    return _inverseInertiaTensor;
}

void RigidBody3D::SetInverseInertiaTensor(const glm::mat4& mat)
{
    _inverseInertiaTensor = glm::inverse(mat);
}

const glm::vec3& RigidBody3D::GetVelocity(void) const
{
    return _velocity;
}

void RigidBody3D::SetVelocity(const glm::vec4& vec)
{
    _velocity = vec;
}


void RigidBody3D::AddScaledVelocity(const glm::vec4& vec, F32 scale)
{
    // This causes an error
    // _velocity += vec * scale;
}

const glm::vec3& RigidBody3D::GetAcceleration(void) const
{
    return _acceleration;
}

void RigidBody3D::SetAcceleration(const glm::vec4& vec)
{
    _acceleration = vec;
}

void RigidBody3D::AddScaledAcceleration(const glm::vec4& vec, F32 scale)
{
    // This causes an error
    //_acceleration += vec * scale;
}

const glm::vec3& RigidBody3D::GetRotation(void) const
{
    return _rotation;
}

void RigidBody3D::SetRotation(const glm::vec3& vec)
{
    _rotation = vec;
}


void RigidBody3D::AddScaledRotation(const glm::vec3& vec, F32 scale)
{
    _rotation += vec * scale;
}

const glm::vec3& RigidBody3D::GetForces(void) const
{
    return _forceAccum;
}

void RigidBody3D::AddForce(const glm::vec3& force)
{
    _forceAccum += force;
    _isAwake = true;
}

const glm::vec3& RigidBody3D::GetTorque(void) const
{
    return _torqueAccum;
}

void RigidBody3D::AddTorque(const glm::vec3& torque)
{
    _torqueAccum += torque;
}

void RigidBody3D::ClearAccumulators(void)
{
    _forceAccum = glm::vec3(0.0f);
    _torqueAccum = glm::vec3(0.0f);
}

void RigidBody3D::AddForceAtPoint(const glm::vec3& force, const glm::vec3& point)
{
    if (_obj == nullptr)
    {
        assert("RigidBody3D::AddForceAtPoint: object not set!");
    }

    glm::vec3 pt{};
    pt -= _obj->GetPosition();

    _forceAccum += force;
    _torqueAccum += glm::cross(pt, force);

    _isAwake = true;
}

real RigidBody3D::GetInverseMass(void) const
{
    return _inverseMass;
}

void RigidBody3D::SetInverseMass(real val)
{
    _inverseMass = val;
}

bool RigidBody3D::HasFiniteMass(void) const
{
    return _inverseMass >= 0.0f;
}

const real RigidBody3D::GetMass(void)
{
    if (_inverseMass == 0.0f)
    {
        return REAL_MAX;
    }
    else
    {
        return static_cast<real>(1.0f) / _inverseMass;
    }
}

void RigidBody3D::SetMass(real mass)
{
    assert(mass != 0.0f);
    _inverseMass = static_cast<real>(1.0f) / mass;
}

real RigidBody3D::GetLinearDamping(void) const
{
    return _linearDamping;
}

void RigidBody3D::SetLinearDamping(real val)
{
    _linearDamping = val;
}

real RigidBody3D::GetAngularDamping(void) const
{
    return _angularDamping;
}

void RigidBody3D::SetAngularDamping(real val)
{
    _angularDamping = val;
}

bool RigidBody3D::GetIsAwake(void)
{
    return _isAwake;
}

void RigidBody3D::SetEntity(p_Entity obj)
{
    _obj = obj;
}

const glm::vec3 RigidBody3D::GetPosition(void)
{
    if (_obj == nullptr)
    {
        assert("RigidBody3D::GetPosition error! No Entity is set!");
    }
    return _obj->GetPosition();
}

/*
    This needs:
    1. GameObject to cache the world transform Matrix4 - should be done
    2. multiply the _invserInertiaTensorInWorld by it.

    The book is confusing. This must be high performance, it will be called every frame.
    Add this in when actually doing something interesting with 3D rigid bodies. For now
    everything is 2D.
*/
void RigidBody3D::_TransformInertiaTensor(void)
{

}