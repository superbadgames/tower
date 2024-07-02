#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Tower
{
    struct Transform
    {
        glm::mat4 transform{ 1.0 };
        glm::vec3 position{ 0.0f };
        glm::vec3 rotationAxis{ 1.0f };
        glm::vec3 scale{ 1.0f };
        glm::vec4 color{ 0.0f };
        real rotationAngle{ 0 };

        inline const glm::mat4& GetTransform(void)
        {
            transform = glm::mat4(1.0);

            transform = glm::translate(transform, position);
            transform = glm::rotate(transform, RADIAN(rotationAngle), rotationAxis);
            transform = glm::scale(transform, scale);

            return transform;
        }
    };
    typedef shared_ptr<Transform> p_Transform;
};