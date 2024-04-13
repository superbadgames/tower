#include "pch.h"
#include "Tower/Physics/Force/AnchoredSpring.h"
using namespace Tower;

AnchoredSpring::AnchoredSpring(void):
    _anchor(0.0f),
    _springConstant(1),
    _restLength(1)
{  }

AnchoredSpring::AnchoredSpring(const glm::vec3& anchor, real springConstant, real restLength):
    _anchor(anchor),
    _springConstant(springConstant),
    _restLength(restLength)
{  }

AnchoredSpring::~AnchoredSpring(void)
{  }

void AnchoredSpring::v_UpdateForce(p_RigidBody2D otherBody)
{
    //     //Calculate thevector of the spring
    //     glm::vec2 force = otherBody->GetPosition() - glm::vec2(_anchor);
    //     force -= _anchor;

    //     //Calculate the magnitude of the force
    //     real magnitude = glm::length(force);
    //     magnitude = (_restLength - magnitude) * _springConstant;

    //     //Calculate the final force and apply it
    //     force = glm::normalize(force);
    //   //  force *= static_cast<F32>(magnitude);
    //     otherBody->AddForce(force);
}

//TODO: Implement
void AnchoredSpring::v_UpdateForce(p_RigidBody3D body)
{
    // glm::vec3 force = body->GetPosition();
    // force -= _anchor;

    // //Calculate the magnitude of the force
    // real magnitude = glm::length(force);
    // magnitude = (_restLength - magnitude) * _springConstant;

    // //Calculate the final force and apply it
    // force = glm::normalize(force);
    // //force *= static_cast<F32>(magnitude);
    // body->AddForce(force);
}

void AnchoredSpring::SetAnchor(const glm::vec3& anchor)
{
    _anchor = anchor;
}

void AnchoredSpring::SetSpringConstant(real constant)
{
    _springConstant = constant;
}

void AnchoredSpring::SetRestLength(real length)
{
    _restLength = length;
}