#pragma once

#include "pch.h"
#include "Tower/framework.h"

namespace Tower
{
    enum InputButtonState
    {
        RELEASE = GLFW_RELEASE,
        PRESS = GLFW_PRESS,
        HOLD = GLFW_REPEAT,
        NONE
    };
}