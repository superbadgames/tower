#include "pch.h"
#include "Tower/Rendering/VertexAttribute.hpp"

using namespace Tower;

VertexAttribute::VertexAttribute(void):
    _count(0),
    _vbo(0),
    _location(0)
{  }

VertexAttribute::~VertexAttribute(void)
{
    glDeleteBuffers(1, &_vbo);
}

void VertexAttribute::Init(U32 location)
{
    glGenBuffers(1, &_vbo);
    _location = location;
}

void VertexAttribute::SetVec2(const std::vector<F32>& values)
{
    Bind();
    glBufferData(GL_ARRAY_BUFFER, sizeof(F32) * values.size(), &values[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(_location);
    glVertexAttribPointer(_location, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    Unbind();
}

void VertexAttribute::SetVec3(const std::vector<F32>& values)
{
    Bind();

    glBufferData(GL_ARRAY_BUFFER, sizeof(F32) * values.size(), &values[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(_location);
    glVertexAttribPointer(_location, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    Unbind();
}

void VertexAttribute::Bind(void)
{
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
}

void VertexAttribute::Unbind(void)
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}