#include "pch.h"
#include "Tower/Components/Transform.hpp"

using namespace Tower;

glm::mat4 Transform::ToMatrix(void) const
{
    glm::mat4 result = glm::mat4(1.0);

    result = glm::translate(result, _position);
    result = glm::rotate(result, _rotation.ToVec3());
    result = glm::scale(result, _scale);

    return result;
}