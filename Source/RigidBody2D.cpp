#include "pch.h"
#include "Tower/Physics/RigidBody/RigidBody2D.h"
using namespace Tower;

RigidBody2D::RigidBody2D(void) : _active(true),
                                 _inverseMass(1.0f),
                                 _inverseMomentOfInertia(1.0f),
                                 _linearDamping(0.999f),
                                 _angularDamping(0.999f),
                                 _obj(nullptr),
                                 _rotation(0.0f),
                                 _velocity(0.0f),
                                 _acceleration(0.0f),
                                 _forceAccum(0.0f),
                                 _gravityForce(0.0f)
{
}

RigidBody2D::RigidBody2D(const RigidBody2D *otherBody) : _active(otherBody->GetActive()),
                                                         _inverseMass(otherBody->GetInverseMass()),
                                                         _inverseMomentOfInertia(otherBody->GetMomentOfInertia()),
                                                         _linearDamping(otherBody->GetLinearDamping()),
                                                         _obj(otherBody->GetEntity()),
                                                         _rotation(otherBody->GetRotation()),
                                                         _velocity(otherBody->GetVelocity()),
                                                         _acceleration(otherBody->GetAcceleration()),
                                                         _forceAccum(otherBody->GetForces()),
                                                         _gravityForce(otherBody->GetGravityForce())
{
}

RigidBody2D::RigidBody2D(const RigidBody2D &otherBody)
    : _active(otherBody.GetActive()),
      _inverseMass(otherBody.GetInverseMass()),
      _inverseMomentOfInertia(otherBody.GetMomentOfInertia()),
      _linearDamping(otherBody.GetLinearDamping()),
      _obj(otherBody.GetEntity()),
      _rotation(otherBody.GetRotation()),
      _velocity(otherBody.GetVelocity()),
      _acceleration(otherBody.GetAcceleration()),
      _forceAccum(otherBody.GetForces()),
      _gravityForce(otherBody.GetGravityForce())
{
}

RigidBody2D::~RigidBody2D(void)
{
    _obj = nullptr;
}

void RigidBody2D::Integrate(void)
{
    // if (_obj == nullptr)
    // {
    //     assert("RigidBody2D::Integrate: object not set!");
    // }

    // if (_inverseMass == 0) return;

    // // TODO:: Pass in delta time
    // //F32 delta = TM::Timer::Instance()->DeltaTime();
    // F32 delta = 0.03f; // locked at 30fps
    // assert(delta > 0.0f);

    // glm::vec2 accelerationLastFrame = _acceleration;
    // real angularAcceleration = _torqueAccum * _inverseMomentOfInertia;

    // _forceAccum += _gravityForce;

    // accelerationLastFrame += _forceAccum * _inverseMass;

    // _velocity += accelerationLastFrame * delta;
    // _rotation += angularAcceleration * delta;

    // _velocity *= real_pow(_linearDamping, delta);
    // _rotation *= real_pow(_angularDamping, delta);

    // _obj->SetPosition(glm::vec3(_velocity * delta, 0.0f));
    // _obj->SetRotationAngle(_rotation * delta);

    // ClearAccumulator();
}

void RigidBody2D::ClearAccumulator(void)
{
    _forceAccum = glm::vec2(0.0f);
    _torqueAccum = 0.0f;
}

p_Entity RigidBody2D::GetEntity(void) const
{
    return _obj;
}

const glm::vec2 &RigidBody2D::GetVelocity(void) const
{
    return _velocity;
}

void RigidBody2D::SetVelocity(const glm::vec2 &vel)
{
    _velocity = vel;
}

const glm::vec2 &RigidBody2D::GetAcceleration(void) const
{
    return _acceleration;
}

void RigidBody2D::SetAcceleration(const glm::vec2 &acc)
{
    _acceleration = acc;
}

const glm::vec2 &RigidBody2D::GetForces(void) const
{
    return _forceAccum;
}

const glm::vec2 &RigidBody2D::GetGravityForce(void) const
{
    return _gravityForce;
}

void RigidBody2D::SetGravityForce(const glm::vec2 &grav)
{
    _gravityForce = grav;
}

const real RigidBody2D::GetInverseMass(void) const
{
    return _inverseMass;
}

void RigidBody2D::SetInverseMass(real inverseMass)
{
    _inverseMass = inverseMass;
}

bool RigidBody2D::HasFiniteMass(void)
{
    return _inverseMass >= 0.0f;
}

void RigidBody2D::SetMass(real mass)
{
    assert(mass != 0.0f);
    _inverseMass = static_cast<real>(1.0f) / mass;
}

const real RigidBody2D::GetLinearDamping(void) const
{
    return _linearDamping;
}

void RigidBody2D::SetLinearDamping(real damp)
{
    _linearDamping = damp;
}

void RigidBody2D::SetActive(bool state)
{
    _active = state;
}

void RigidBody2D::SetEntity(p_Entity obj)
{
    _obj = obj;
}

void RigidBody2D::SetRotation(real euler)
{
    _rotation = euler;
}

real RigidBody2D::GetRotation(void) const
{
    return _rotation;
}

// void RigidBody2D::UpdateVelocityAndAcceleration(const TE::SteeringOutput2D steering)
// {
//     _velocity += steering.linear * TM::Timer::Instance()->DeltaTime();
//     _rotation += steering.angular * TM::Timer::Instance()->DeltaTime();
// }

bool RigidBody2D::GetActive(void) const
{
    if (_obj != nullptr)
    {
        // return _obj->GetActive() && _active;
        return _active;
    }

    return _active;
}

const glm::vec2 RigidBody2D::GetPosition(void) const
{
    // if (_obj == nullptr)
    // {
    //     assert("RigidBody2D::GetPosition Set the GameObject before calling GetPosition");
    // }

    // return _obj->GetPosition();
    return glm::vec2(1.0f);
}

const real RigidBody2D::GetMass(void)
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

void RigidBody2D::AddForce(const glm::vec2 &force)
{
    _forceAccum += force;
}

void RigidBody2D::AddForceAtPoint(const glm::vec2 &force, const glm::vec2 point)
{
    _forceAccum += force;
    _torqueAccum = point.x * force.y - point.y * force.x;
}

void RigidBody2D::SetMomentOfInertia(real inertia)
{
    _inverseMomentOfInertia = 1 / inertia;
}

real RigidBody2D::GetMomentOfInertia(void) const
{
    return _inverseMomentOfInertia;
}

void RigidBody2D::SetAngularDamping(real angularDamping)
{
    _angularDamping = angularDamping;
}

real RigidBody2D::GetAngularDamping(void) const
{
    return _angularDamping;
}