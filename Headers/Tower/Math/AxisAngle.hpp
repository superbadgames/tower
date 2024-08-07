#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec3.hpp>

namespace Tower
{
  struct AxisAngle
  {
    F32 angle{ 0.0f };
    glm::vec3 axis{ glm::vec3(0.0f, 1.0f, 0.0f) };
  };
}