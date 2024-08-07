#include "pch.h"
#include "Tower/Rendering/Sprite.hpp"

using namespace Tower;

Sprite::Sprite(void) :
    _vao(0),
    _vbo(0),
    _ebo(0),
    _texcoordBuffer(0),
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
        1.0f, 1.0f,
        // Bottom Right
        1.0f, -1.0f,
        // Bottom Left
        -1.0f, -1.0f,
        // Top Left
        -1.0f, 1.0f
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
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);
    glGenBuffers(1, &_texcoordBuffer);

    glBindVertexArray(_vao);

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(F32) * _vertices.size(), &_vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, _texcoordBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(F32) * _uvs.size(), &_uvs[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(U32) * _indices.size(), &_indices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(F32), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, _texcoordBuffer);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(F32), (void*)0);
    glEnableVertexAttribArray(1);


    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // DO NOT unbind the element array buffer. This is actually stored in the VAO, and would unbind it
    // from the object completely.
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    _texture = texture;
}

void Sprite::Draw(p_Shader shader, const Color& color)
{
    assert(_texture != nullptr && "Sprite Texture is null.");

    // Set Sprite Specific Uniforms
    // Why is this here? I want any sprite specific shader code to live in the sprite itself.
    // In time, it might make some sense to turn this into it's own function.
    shader->SetUniform("sprite_color", color.ToVec4());

    _texture->Bind();

    glBindVertexArray(_vao);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    _texture->Unbind();
}
