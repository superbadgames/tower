#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Shader.hpp"
#include <unordered_map>

namespace Tower
{
    class ShaderManager
    {
    public:
        ShaderManager(void);

        ~ShaderManager(void);

        void LoadShader(U32 shaderID, const string& vertexFilepath, const string& fragmentFilepath);

        void RegisterShader(U32 shaderID, p_Shader shader);

        p_Shader GetShader(U32 shaderID);

    private:
        std::unordered_map<U32, p_Shader> _shaders;
    };
    typedef shared_ptr<ShaderManager> p_ShaderManager;
}