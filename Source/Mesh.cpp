#include "pch.h"
#include "Tower/Rendering/Mesh.hpp"

using namespace Tower;

Mesh::Mesh(void) :
    _vao(0),
    _vbo(0),
    _ebo(0),
    _vertices(),
    _indices(),
    _texture(nullptr)
{  }

Mesh::~Mesh(void)
{
    glDeleteBuffers(1, &_vbo);
    glDeleteBuffers(1, &_ebo);
    glDeleteVertexArrays(1, &_vao);
    _vertices.clear();
}

void Mesh::Load(const std::vector<Vertex>& vertices, const std::vector<U32> indices, p_Shader shader)
{
    _vertices = vertices;
    _indices = indices;
    _Init(shader);
}

void Mesh::MakeSprite(p_Shader shader)
{
    // Top Right
    _vertexPositions.insert(end(_vertexPositions), { 1.0f, 1.0f });
    _vertexUvs.insert(end(_vertexUvs), { 1.0f, 1.0f });

    // Bottom Right
    _vertexPositions.insert(end(_vertexPositions), { -1.0f, 1.0f });
    _vertexUvs.insert(end(_vertexUvs), { 1.0f, 0.0f });

    // Bottom Left
    _vertexPositions.insert(end(_vertexPositions), { -1.0f, -1.0f });
    _vertexUvs.insert(end(_vertexUvs), { 0.0f, 0.0f });

    // Top Left
    _vertexPositions.insert(end(_vertexPositions), { 1.0f, -1.0f });
    _vertexUvs.insert(end(_vertexUvs), { 0.0f, 1.0f });


    _indices = std::vector<U32>(
        {
            0, 1, 3,     // first triangle
            1, 2, 3     // second triangle
        }
    );

    _InitSprite(shader);
}

void Mesh::Draw(p_Shader shader)
{
    // This may seem over kill, but I added this as a sanity check once.
    if (shader == nullptr)
    {
        assert("You've got no shader in Mesh::Draw");
    }

    shader->Use();
    Use(shader);

    glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);

    StopUse();
    shader->StopUse();
}

void Mesh::Use(p_Shader shader)
{
    if (_texture != nullptr)
    {
        _texture->Bind(0);
    }

    glBindVertexArray(_vao);
}

void Mesh::StopUse(void)
{
    glBindVertexArray(0);

    if (_texture != nullptr)
    {
        _texture->Unbind();
    }
}

void Mesh::EnableWireframeMode(void)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Mesh::DisableWireframeMode(void)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Mesh::_Init(p_Shader shader)
{
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);

    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(F32) * _vertices.size(), &_vertices[0], GL_STATIC_DRAW);

    // Draw Indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(U32) * _indices.size(), &_indices[0], GL_STATIC_DRAW);

    // TODO: Move all of this into the shader class. This is something the shader should abstract away from the model.
    // Here is why. Say I want to change the name of position to pos. If I forget to update the model init code, it will fail.
    // This is not good. This hides a problem. If the shader had all this code, then the model could just say shader->
    // Vertex positions
    U32 location = shader->GetAttributeLocation("position");
    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, sizeof(F32), (void*)0);

    // Vertex uvs
    location = shader->GetAttributeLocation("uvs");
    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, sizeof(U32), (void*)0);


    glBindVertexArray(0);
}

void Mesh::_InitSprite(p_Shader shader)
{
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_vbo);
    glGenBuffers(1, &_ebo);

    glBindVertexArray(_vao);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(F32) * _vertices.size(), &_vertexPositions[0], GL_STATIC_DRAW);

    // Draw Indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(U32) * _indices.size(), &_indices[0], GL_STATIC_DRAW);

    // TODO: Move all of this into the shader class. This is something the shader should abstract away from the model.
    // Here is why. Say I want to change the name of position to pos. If I forget to update the model init code, it will fail.
    // This is not good. This hides a problem. If the shader had all this code, then the model could just say shader->
    // Vertex positions
    U32 location = shader->GetAttributeLocation("position");
    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, sizeof(F32), (void*)0);

    // Vertex uvs
    location = shader->GetAttributeLocation("uvs");
    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, sizeof(U32), (void*)0);


    glBindVertexArray(0);
}
