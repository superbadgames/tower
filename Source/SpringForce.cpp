#include "pch.h"
#include "Tower/Physics/Force/SpringForce.h"
using namespace Tower;

SpringForce::SpringForce(void):
    _otherEnd(),
    _springConstant(1),
    _restLength(1),
    _isBungie(false)
{  }

SpringForce::SpringForce(shared_ptr<RigidBody2D> otherEnd, real springConstatant, real restLength):
    _otherEnd(otherEnd),
    _springConstant(springConstatant),
    _restLength(restLength),
    _isBungie(false)
{  }

SpringForce::~SpringForce(void)
{  }


void SpringForce::v_UpdateForce(shared_ptr<RigidBody2D> RigidBody2D)
{
    // glm::vec2 force{};
    // force = RigidBody2D->GetPosition();
    // force -= _otherEnd->GetPosition();

    // real magnitude = glm::length(force);

    // if (_isBungie && magnitude <= _restLength)
    // {
    //     return;
    // }

    // magnitude = real_abs(magnitude - _restLength) * _springConstant;

    // force = glm::normalize(force);
    // force *= static_cast<F32>(-magnitude);

    // RigidBody2D->AddForce(force);
}
