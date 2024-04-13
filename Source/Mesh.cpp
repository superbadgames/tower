#include "pch.h"
#include "Tower/Rendering/Mesh.hpp"

using namespace Tower;

Mesh::Mesh(void):
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
    Vertex topRight;
    topRight.position = glm::vec3(1.0f, 1.0f, 0.0f);
    topRight.uvs = glm::vec2(1.0f, 1.0f);

    Vertex bottomRight;
    bottomRight.position = glm::vec3(1.0f, -1.0f, 0.0f);
    bottomRight.uvs = glm::vec2(1.0f, 0.0f);

    Vertex bottomLeft;
    bottomLeft.position = glm::vec3(-1.0f, -1.0f, 0.0);
    bottomLeft.uvs = glm::vec2(0.0f, 0.0f);

    Vertex topLeft;
    topLeft.position = glm::vec3(-1.0f, 1.0f, 0.0f);
    topLeft.uvs = glm::vec2(0.0f, 1.0f);

    _vertices.push_back(topRight);
    _vertices.push_back(bottomRight);
    _vertices.push_back(bottomLeft);
    _vertices.push_back(topLeft);

    _indices = std::vector<U32>(
        {
            0, 1, 3,     // first triangle
            1, 2, 3     // second triangle
        }
    );

    _Init(shader);
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

    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * _vertices.size(), &_vertices[0], GL_STATIC_DRAW);

    // Draw Indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(U32) * _indices.size(), &_indices[0], GL_STATIC_DRAW);

    // Vertex positions
    U32 location = shader->GetAttributeLocation("position");
    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    // Vertex uvs
    location = shader->GetAttributeLocation("uvs");
    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uvs));


    glBindVertexArray(0);
}
