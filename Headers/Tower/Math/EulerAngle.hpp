#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Tower
{
    struct EulerAngle
    {
        F32 yaw;
        F32 pitch;
        F32 roll;

        inline glm::quat ToQuat(void) const { return glm::quat(glm::vec3(yaw, pitch, roll)); }

        inline glm::vec3 ToVec3(void) const { return glm::vec3(yaw, pitch, roll); }
    };
}