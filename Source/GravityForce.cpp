#include "pch.h"
#include "Tower/Physics/Force/GravityForce.h"
using namespace Tower;

GravityForce::GravityForce(void):
    _gravityAcc(0.0f, -1.0f, 0.0f)
{  }

GravityForce::GravityForce(const glm::vec3& gravity):
    _gravityAcc(gravity)
{  }

GravityForce::~GravityForce(void)
{  }

void GravityForce::v_UpdateForce(p_RigidBody2D body)
{
    if (!body->HasFiniteMass())
    {
        return;
    }

    real mass = body->GetMass();

    body->AddForce(glm::vec2(_gravityAcc * mass));
}

void GravityForce::v_UpdateForce(p_RigidBody3D body)
{
    if (!body->HasFiniteMass())
    {
        return;
    }

    body->AddForce(_gravityAcc * body->GetMass());
}