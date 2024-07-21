#include "pch.h"
#include "Tower/Rendering/Sprite.hpp"

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

void Sprite::Init(p_Texture texture)
{
    // Create the sprite geometry
    _vertices.insert(_vertices.end(), {
        // Top Right
        0.5f, 0.5f,
        // Bottom Right
        0.5f, -0.5f,
        // Bottom Left
        -0.5f, -0.5f,
        // Top Left
        -0.5f, 0.5f
        });

    // Create uvs
    _uvs.insert(_uvs.end(), {
        // Top Right
        1.0f, 1.0f,
        // Bottom Right
        1.0f, 0.0f,
        // Bottom Left
        0.0f, 0.0f,
        // Top Left
        0.0f, 1.0f
        });

    // Create indices
    _indices.insert(_indices.end(), {
        // Triangle 1
        0, 1, 2,
        // Triangle 2
        2, 3, 0
        });



    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);

    glBindVertexArray(_vao);

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(F32) * _vertices.size(), &_vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(U32) * _indices.size(), &_indices[0], GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(F32), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // DO NOT unbind the element array buffer. This is actually stored in the VAO, and would unbind it
    // from the object completely.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    _texture = texture;
}

void Sprite::Draw(void)
{
    _texture->Bind();
    glBindVertexArray(_vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    _texture->Unbind();
}

