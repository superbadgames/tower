#include "pch.h"
#include "Tower/Physics/Force/DragForce.h"

using namespace Tower;

DragForce::DragForce(void)
    :
    _drag(0.0f),
    _dragSqr(0.0f)
{  }

DragForce::DragForce(real drag)
    :
    _drag(drag),
    _dragSqr(_drag* _drag)
{  }

DragForce::~DragForce(void)
{  }

void DragForce::v_UpdateForce(shared_ptr<RigidBody2D> RigidBody2D)
{
    // glm::vec2 force = RigidBody2D->GetVelocity();

    // real dragCoeff = glm::length(force);
    // dragCoeff = _drag * dragCoeff + _dragSqr * dragCoeff * dragCoeff;

    // force = glm::normalize(force);
    // force *= -dragCoeff;

    // RigidBody2D->AddForce(force);
}

void DragForce::v_UpdateForce(shared_ptr<RigidBody3D> body)
{
    // glm::vec3 force = body->GetVelocity();

    // real dragCoeff = glm::length(force);
    // dragCoeff = _drag * dragCoeff + _dragSqr * dragCoeff * dragCoeff;

    // force = glm::normalize(force);
    // force *= -dragCoeff;

    // body->AddForce(force);
}