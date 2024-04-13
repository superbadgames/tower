#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#include <GLFW/glfw3.h>
#include <vector>

namespace Tower
{
    class Uniform
    {
    public:
        static void Set(U32 slot, const S32& value);

        static void Set(U32 slot, const F32& value);

        static void Set(U32 slot, const glm::vec2& value);

        static void Set(U32 slot, const glm::vec3& value);

        static void Set(U32 slot, const glm::vec4& value);

        static void Set(U32 slot, const glm::ivec2& value);

        static void Set(U32 slot, const glm::ivec4& value);

        static void Set(U32 slot, const glm::quat& value);

        static void Set(U32 slot, const glm::mat4& value);

    private:
        Uniform(void);
        Uniform(const Uniform&);
        ~Uniform(void);
        Uniform operator=(const Uniform&);
    };
}