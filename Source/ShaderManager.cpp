#include "pch.h"
#include "Tower/Managers/ShaderManager.hpp"

using namespace Tower;

p_ShaderManager _instance = nullptr;

ShaderManager::ShaderManager(void)
{

}

ShaderManager::~ShaderManager(void)
{
    _shaders.clear();
}

void ShaderManager::LoadShader(U32 shaderID, const string& vertexFilepath, const string& fragmentFilepath)
{
    if (_shaders.find(shaderID) != _shaders.end())
    {
        string msg = "Error! ShaderManager::LoadShader called with duplicated ID " + shaderID;
        assert(msg.c_str());
    }

    p_Shader shader = std::make_shared<Shader>();
    shader->Load(vertexFilepath, fragmentFilepath);

    _shaders[shaderID] = shader;
}

void ShaderManager::RegisterShader(U32 shaderID, p_Shader shader)
{
    if (_shaders.find(shaderID) != _shaders.end())
    {
        string msg = "Error! ShaderManager::LoadShader called with duplicated ID " + shaderID;
        assert(msg.c_str());
    }

    _shaders[shaderID] = shader;
}

p_Shader ShaderManager::GetShader(U32 shaderID)
{
    if (_shaders.find(shaderID) == _shaders.end())
    {
        string msg = "Error! ShaderManager::GetShader unable to find shader ID " + shaderID;
        assert(msg.c_str());
    }

    return _shaders[shaderID];
}