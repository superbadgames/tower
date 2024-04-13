#pragma once
#include "pch.h"
#include "Tower/framework.h"
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <vector>

namespace Tower
{
    class VertexAttribute
    {
    public:
        VertexAttribute(void);

        ~VertexAttribute(void);

        void Init(U32 location);

        void SetVec2(const std::vector<F32>& values);

        void SetVec3(const std::vector<F32>& values);

        void Bind(void);

        void Unbind(void);

    private:
        U32 _count;
        GLuint _vbo;
        U32 _location;
    };
}