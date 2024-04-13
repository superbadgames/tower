#pragma once
#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Uniform.hpp"
#include "Tower/Rendering/VertexAttribute.hpp"
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <map>

namespace Tower
{
    // TODO: At various stages in the shader Load, the process can fail.
    // Currently, this is all checked and output via std::cout. Consider
    // adding a more expressive logging system, disabling the logging when
    // not in debug, and implementing exceptions, with try/catch blocks.
    class Shader
    {
    public:
        Shader(void);

        ~Shader(void);

        void Load(const string& vertexFilepath, const string& fragmentFilepath);

        void Use(void);

        void StopUse(void);

        U32 GetAttributeLocation(const string& name);

        void PrintAllAttributes(void);

        void PrintAllUniforms(void);

        U32 GetUniform(string name);

        void SetUniform(string name, const S32& value);

        void SetUniform(string name, const F32& value);

        void SetUniform(string name, const glm::vec2& value);

        void SetUniform(string name, const glm::vec3& value);

        void SetUniform(string name, const glm::vec4& value);

        void SetUniform(string name, const glm::ivec2& value);

        void SetUniform(string name, const glm::ivec4& value);

        void SetUniform(string name, const glm::quat& value);

        void SetUniform(string name, const glm::mat4& value);

    private:
        GLuint _shaderHandle;
        std::map<string, U32> _attributeLocations;
        std::map<string, U32> _uniforms;

        // Don't allow copy
        Shader(const Shader&);
        Shader& operator=(const Shader&);

        U32 _CompileShader(const string& path, GLenum type);

        // True == Linking was successful
        // False == Linking failed
        bool _LinkShaders(U32 vertex, U32 fragment);

        void _PopulateAttributes(void);

        void _PopulateUniforms(void);

        const string _GetShaderSourceFromFile(const string& path);

        // True == There were errors found, you have a problem
        // False == Everything is good, no errors found.
        bool _CheckForCompileErrors(U32 shader);

        void _CheckForUniform(string name);
    };
    typedef shared_ptr<Shader> p_Shader;
}