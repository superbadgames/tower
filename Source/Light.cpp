#include "pch.h"
#include "Tower/Rendering/Light.hpp"

using namespace Tower;

Light::Light(void) : _color{ 1.0f, 1.0f, 1.0f },
_direction{ 0.0f, -1.0f, 0.0f },
_ambient(1.0f),
_diffuse(0.0f)
{
}

Light::Light(glm::vec3 color, glm::vec3 direction, real ambient, real diffuse) : _color{ color },
_direction{ direction },
_ambient{ ambient },
_diffuse{ diffuse }
{
}

Light::~Light(void)
{
}

// void Light::UpdateGPU(Shader &shader)
// {
// }
