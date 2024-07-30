#include "pch.h"
#include "Tower/Physics/Particle.hpp"

using namespace Tower;

Particle::Particle(void) : _entity(nullptr),
                           _velocity(0.0f),
                           _acceleration(0.0f),
                           _inverseMass(1.0f)
{
}

Particle::Particle(p_Entity entity) : _entity(entity),
                                      _velocity(0.0f),
                                      _acceleration(0.0f),
                                      _inverseMass(1.0f)
{
}

Particle::~Particle(void)
{
    _entity.reset();
}

void Particle::SetMass(F32 mass)
{
    if (mass <= 0.0f)
    {
        _inverseMass = 0.0f;
    }

    _inverseMass = 1 / mass;
}

void Particle::Integrate(F32 delta)
{
    // if (_inverseMass <= 0.0f) return;

    // glm::vec3 position = _entity->GetPosition();

    // position += _velocity * delta;

    // // TODO: Add forces from generators into the final acceleration
    // glm::vec3 finalAcceleration = _acceleration;

    // _velocity += finalAcceleration * delta;

    // _velocity *= real_pow(_damping, delta);

    // _entity->SetPosition(position);
    // _ClearForceAccumulators();
}

void Particle::_ClearForceAccumulators(void)
{
}