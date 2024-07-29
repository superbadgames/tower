#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Math/EulerAngle.hpp"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    class Transform
    {
    public:


        glm::mat4 ToMatrix(void) const;

    private:
        glm::vec3 _position;
        glm::vec3 _scale;
        EulerAngle _rotation;
    };
    typedef shared_ptr<Transform> p_Transform;
};