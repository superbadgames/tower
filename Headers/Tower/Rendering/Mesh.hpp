#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Texture.hpp"
#include "Tower/Rendering/VertexAttribute.hpp"
#include "Tower/Rendering/Shader.hpp"
#include "Tower/Rendering/Vertex.hpp"
#include "glm/vec4.hpp"
#include <vector>

namespace Tower
{
    class Mesh
    {
    public:
        Mesh(void);

        ~Mesh(void);

        void Load(const std::vector<Vertex>& vertices, const std::vector<U32> indices, p_Shader shader);

        void MakeSprite(p_Shader shader);

        void Draw(p_Shader shader);

        void Use(p_Shader shader);

        void StopUse(void);

        void EnableWireframeMode(void);

        void DisableWireframeMode(void);

        inline void SetTexture(p_Texture texture) { _texture = texture; }

    private:
        GLuint _vao;    // Vertex Array Object
        GLuint _vbo;    // Vertex Buffer Object
        GLuint _ebo;    // Element Buffer Object
        std::vector<Vertex> _vertices;
        std::vector<U32> _indices;
        // TODO: This needs to change to an array of textures.
        // Also, materials need to be added.
        p_Texture _texture;

        void _Init(p_Shader shader);
    };
    typedef shared_ptr<Mesh> p_Mesh;
}