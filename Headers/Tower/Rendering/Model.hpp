#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Texture.hpp"
#include "Tower/Rendering/Mesh.hpp"
#include "Tower/Rendering/Shader.hpp"
#include "glm/vec4.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <vector>

namespace Tower
{
    class Model
    {
    public:
        Model(void);

        ~Model(void);

        void CreateSprite(p_Shader shader, p_Texture texture);

        void LoadFromFile(p_Shader shader, const string& filepath);

        void LoadFromFile(const string& filepath);

        void Draw(void);

        void EnableWireframeMode(void);

        void DisableWireframeMode(void);

        // void SetColor(const glm::vec4& color);

        inline void SetShader(p_Shader shader) { _shader = shader; }

        inline void SetTexture(p_Texture texture) { _texture = texture; }

    private:
        std::vector<p_Mesh> _meshes;
        p_Texture _texture;
        p_Shader _shader;

        void _ProcessNode(aiNode* node, const aiScene* scene);

        p_Mesh _ProcessMesh(aiMesh* mesh, const aiScene* scene);
    };
    typedef shared_ptr<Model> p_Model;
}