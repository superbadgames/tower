#include "pch.h"
#include "Tower/Rendering/Model.hpp"

using namespace Tower;

Model::Model(void):
    _meshes(),
    _texture(nullptr),
    _shader(nullptr)
{

}

Model::~Model(void)
{  }

void Model::CreateSprite(p_Shader shader, p_Texture texture)
{
    p_Mesh mesh = std::make_shared<Mesh>();
    _shader = shader;
    mesh->MakeSprite(shader);
    mesh->SetTexture(texture);
    _meshes.push_back(mesh);
}

void Model::LoadFromFile(p_Shader shader, const string& filepath)
{
    _shader = shader;
    LoadFromFile(filepath);
}

void Model::LoadFromFile(const string& filepath)
{
    // There must be a shader already
    assert(_shader != nullptr && "Model::LoadFromFile has no shader!\n");


    Assimp::Importer importer;

    const aiScene* scene = importer.ReadFile(filepath, aiProcess_Triangulate | aiProcess_FlipUVs);

    if (scene == nullptr || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        string msg = "Model::LoadFromFilePath failed to load " + filepath;
        msg = msg + "\n#\n#\n========================Start error log========================\n#\n#\n";
        msg = msg + importer.GetErrorString();
        assert(msg.c_str());
    }

    _ProcessNode(scene->mRootNode, scene);
}


void Model::Draw(void)
{
    if (_texture != nullptr)
    {
        _texture->Bind();
    }

    for (auto mesh : _meshes)
    {
        mesh->Draw(_shader);
    }

    if (_texture != nullptr)
    {
        _texture->Unbind();
    }
}

void Model::EnableWireframeMode(void)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Model::DisableWireframeMode(void)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Model::_ProcessNode(aiNode* node, const aiScene* scene)
{
    // static U32 count = 1;
    // if (count == 1)
    // {
    //     std::cout << "===================================Process Node===================================\n";
    // }
    // std::cout << "Number of calls to Process Node: " << count << std::endl;
    // std::cout << "Number of Meshes: " << scene->mNumMeshes << std::endl;

    for (U32 i = 0; i < node->mNumMeshes; i++)
    {
        //std::cout << "Process Mesh " << i << std::endl;
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        _meshes.push_back(_ProcessMesh(mesh, scene));
    }

    for (U32 i = 0; i < node->mNumChildren; i++)
    {
        _ProcessNode(node->mChildren[i], scene);
    }
}

p_Mesh Model::_ProcessMesh(aiMesh* mesh, const aiScene* scene)
{
    std::vector<Vertex> vertices;
    std::vector<U32> indices;

    p_Mesh myMesh = std::make_shared<Mesh>();

    // std::cout << "=====Process Mesh=====\n"
    //     << "Number of Vertices: " << mesh->mNumVertices << std::endl;

    for (U32 i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;
        vertex.position.x = mesh->mVertices[i].x;
        vertex.position.y = mesh->mVertices[i].y;
        vertex.position.z = mesh->mVertices[i].z;

        vertex.normal.x = mesh->mNormals[i].x;
        vertex.normal.y = mesh->mNormals[i].y;
        vertex.normal.z = mesh->mNormals[i].z;

        if (mesh->mTextureCoords[0])
        {
            vertex.uvs.x = mesh->mTextureCoords[0][i].x;
            vertex.uvs.y = mesh->mTextureCoords[0][i].y;
        }

        vertices.push_back(vertex);
    }

    //std::cout << "Number of Faces: " << mesh->mNumFaces << std::endl;
    for (U32 i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        //std::cout << "For face " << i << ", got this Number of Indices: " << face.mNumIndices << std::endl;
        for (U32 j = 0; j < face.mNumIndices; j++)
        {
            //std::cout << "Got index " << j << " equal to " << face.mIndices[j] << std::endl;
            indices.push_back(face.mIndices[j]);
        }
    }

    //std::cout << "I got a total of " << indices.size() << " Indices\n";

    myMesh->Load(vertices, indices, _shader);


    return myMesh;

}
