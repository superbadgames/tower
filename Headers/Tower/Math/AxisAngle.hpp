#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec3.hpp>

namespace Tower
{
  struct AxisAngle
  {
    F32 angle;
    glm::vec3 axis;
  };
}