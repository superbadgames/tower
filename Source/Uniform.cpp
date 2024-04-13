#include "pch.h"
#include "Tower/Rendering/Uniform.hpp"

using namespace Tower;

void Uniform::Set(U32 slot, const S32& value)
{
    glUniform1i(slot, value);
}

void Uniform::Set(U32 slot, const F32& value)
{
    glUniform1f(slot, value);
}

void Uniform::Set(U32 slot, const glm::vec2& value)
{
    glUniform2f(slot, value.x, value.y);
}

void Uniform::Set(U32 slot, const glm::vec3& value)
{
    glUniform3f(slot, value.x, value.y, value.z);
}

void Uniform::Set(U32 slot, const glm::vec4& value)
{
    glUniform4f(slot, value.x, value.y, value.z, value.w);
}

void Uniform::Set(U32 slot, const glm::ivec2& value)
{
    glUniform2i(slot, value.x, value.y);
}

void Uniform::Set(U32 slot, const glm::ivec4& value)
{
    glUniform4i(slot, value.x, value.y, value.z, value.w);
}

void Uniform::Set(U32 slot, const glm::quat& value)
{
    glUniform4f(slot, value.x, value.y, value.z, value.w);
}

void Uniform::Set(U32 slot, const glm::mat4& value)
{
    glUniformMatrix4fv(slot, 1, GL_FALSE, glm::value_ptr(value));
}
