#include "pch.h"
#include "Tower/Math/Transform.hpp"

using namespace Tower;

Transform::Transform(void) :
    _position(0.0f),
    _scale(1.0f),
    _rotation()
{

}

Transform::~Transform(void)
{

}

glm::mat4 Transform::ToMatrix(void) const
{
    glm::mat4 result = glm::mat4(1.0);

    result = glm::translate(result, _position);
    result = glm::rotate(result, RADIAN(_rotation.angle), _rotation.axis);
    result = glm::scale(result, _scale);

    return result;
}

void Transform::SetRotation(F32 angle, const glm::vec3& axis)
{
    _rotation.angle = angle;
    _rotation.axis = axis;
}