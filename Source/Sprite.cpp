#include "pch.h"
#include "Tower/Rendering/Sprite.hpp"

#include <iostream>

using namespace Tower;

Sprite::Sprite(void) :
    _vao(0),
    _vbo(0),
    _vertices()
{

}

Sprite::~Sprite(void)
{
    glDeleteVertexArrays(1, &_vao);
    glDeleteBuffers(1, &_vbo);
}

void Sprite::Init(void)
{
    _vertices.push_back(-0.5f);
    _vertices.push_back(-0.5f);
    _vertices.push_back(0.0f);

    _vertices.push_back(0.5f);
    _vertices.push_back(-0.5f);
    _vertices.push_back(0.0f);

    _vertices.push_back(0.0f);
    _vertices.push_back(0.5f);
    _vertices.push_back(0.0f);


    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);

    glBindVertexArray(_vao);

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(F32) * _vertices.size(), &_vertices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(F32), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Sprite::Draw(void)
{
    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

