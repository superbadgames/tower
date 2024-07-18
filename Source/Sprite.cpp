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
    _vertices[0] = -0.5f;
    _vertices[1] = -0.5f;
    _vertices[2] = 0.0f;

    _vertices[3] = 0.5f;
    _vertices[4] = -0.5f;
    _vertices[5] = 0.0f;

    _vertices[6] = 0.0f;
    _vertices[7] = 0.5f;
    _vertices[8] = 0.0f;


    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);

    glBindVertexArray(_vao);

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(F32), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Sprite::Draw(void)
{
    std::cout << "Sprite::Draw is called...\n";
    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

