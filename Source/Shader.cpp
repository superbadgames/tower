#include "pch.h"
#include "Tower/Rendering/Shader.hpp"

using namespace Tower;

Shader::Shader(void) :
    _shaderHandle(0),
    _attributeLocations{},
    _uniforms{} {};

Shader::~Shader(void)
{
    glDeleteProgram(_shaderHandle);
};

void Shader::Load(const string& vertexFilepath, const string& fragmentFilepath)
{
    _shaderHandle = glCreateProgram();

    if (!_shaderHandle)
    {
        assert("The shader program is fucked.");
    }

    GLuint vertexShaderHandle = _CompileShader(vertexFilepath, GL_VERTEX_SHADER);

    if (vertexShaderHandle == 0)
    {
        std::cout << "Error! Unable to compile the vertex shader\n";
        return;
    }

    GLuint fragmentShaderHandle = _CompileShader(fragmentFilepath, GL_FRAGMENT_SHADER);
    if (fragmentShaderHandle == 0)
    {
        std::cout << "Error! Unable to compile the fragment shader\n";
        return;
    }

    bool success = _LinkShaders(vertexShaderHandle, fragmentShaderHandle);

    if (!success)
    {
        std::cout << "Error! Unable to link shaders\n";
        glDeleteShader(vertexShaderHandle);
        glDeleteShader(fragmentShaderHandle);
    }

    _PopulateAttributes();

    _PopulateUniforms();
}

void Shader::Use(void)
{
    glUseProgram(_shaderHandle);
}

void Shader::StopUse(void)
{
    glUseProgram(0);
}

U32 Shader::GetAttributeLocation(const string& name)
{
    if (_attributeLocations.find(name) != _attributeLocations.end())
    {
        string message = "Error! Shader does not have attribute " + name;
        assert(message.c_str());
    }
    return _attributeLocations[name];
}

void Shader::PrintAllAttributes(void)
{
    std::cout << "Shader Attributes:" << std::endl;
    for (auto pair : _attributeLocations)
    {
        std::cout << "Name:" << pair.first << "\tLocation:" << pair.second << std::endl;
    }
}

void Shader::PrintAllUniforms(void)
{
    std::cout << "Shader Uniforms:" << std::endl;
    for (auto pair : _uniforms)
    {
        std::cout << "Name:" << pair.first << "\tLocation:" << pair.second << std::endl;
    }
}

U32 Shader::GetUniform(string name)
{
    return _uniforms[name];
}

void Shader::SetUniform(string name, const S32& value)
{
    Use();
    _CheckForUniform(name);
    Uniform::Set(_uniforms[name], value);
    StopUse();
}

void Shader::SetUniform(string name, const F32& value)
{
    Use();
    _CheckForUniform(name);
    Uniform::Set(_uniforms[name], value);
    StopUse();
}

void Shader::SetUniform(string name, const glm::vec2& value)
{
    Use();
    _CheckForUniform(name);
    Uniform::Set(_uniforms[name], value);
    StopUse();
}

void Shader::SetUniform(string name, const glm::vec3& value)
{
    Use();
    _CheckForUniform(name);
    Uniform::Set(_uniforms[name], value);
    StopUse();
}

void Shader::SetUniform(string name, const glm::vec4& value)
{
    Use();
    _CheckForUniform(name);
    Uniform::Set(_uniforms[name], value);
    StopUse();
}

void Shader::SetUniform(string name, const glm::ivec2& value)
{
    Use();
    _CheckForUniform(name);
    Uniform::Set(_uniforms[name], value);
    StopUse();
}

void Shader::SetUniform(string name, const glm::ivec4& value)
{
    Use();
    _CheckForUniform(name);
    Uniform::Set(_uniforms[name], value);
    StopUse();
}

void Shader::SetUniform(string name, const glm::quat& value)
{
    Use();
    _CheckForUniform(name);
    Uniform::Set(_uniforms[name], value);
    StopUse();
}

void Shader::SetUniform(string name, const glm::mat4& value)
{
    Use();
    _CheckForUniform(name);
    Uniform::Set(_uniforms[name], value);
    StopUse();
}

// TODO: Maybe this should throw. That way it could be wrapped in a try/catch.
U32 Shader::_CompileShader(const string& path, GLenum type)
{
    U32 tempShader = glCreateShader(type);

    const string source = _GetShaderSourceFromFile(path);

    const char* data = source.c_str();

    glShaderSource(tempShader, 1, &data, NULL);
    glCompileShader(tempShader);

    if (_CheckForCompileErrors(tempShader))
    {
        glDeleteShader(tempShader);
        return 0;
    }

    return tempShader;
}

bool Shader::_LinkShaders(U32 vertex, U32 fragment)
{
    glAttachShader(_shaderHandle, vertex);
    glAttachShader(_shaderHandle, fragment);

    glLinkProgram(_shaderHandle);

    S32 success = 0;
    glGetProgramiv(_shaderHandle, GL_LINK_STATUS, &success);

    if (!success)
    {
        char logs[1024];
        glGetProgramInfoLog(_shaderHandle, 1024, NULL, logs);
        std::cout << "Shader failed to Link." << std::endl
            << "\t" << logs << std::endl;
        return false;
    }
    return true;
}

void Shader::_PopulateAttributes(void)
{
    S32 numberOfAttributes = -1;
    S32 length = 0;
    S32 size = 0;
    char name[256];
    GLenum type;

    Use();
    glGetProgramiv(_shaderHandle, GL_ACTIVE_ATTRIBUTES, &numberOfAttributes);

    for (S32 i = 0; i < numberOfAttributes; i++)
    {
        // Erase the name, basically filling the array with 0's
        memset(name, 0, sizeof(char) * 128);

        // Get the name of the next attribute in the list
        glGetActiveAttrib(_shaderHandle, (GLuint)i, 128, &length, &size, &type, name);

        // Get the index of the next attribute in the list
        S32 location = glGetAttribLocation(_shaderHandle, name);

        if (location >= 0)
        {
            _attributeLocations[name] = location;
        }
    }
    StopUse();
}

const string Shader::_GetShaderSourceFromFile(const string& path)
{
    std::ifstream file{};
    std::stringstream sourceCode;

    file.open(path.c_str());

    if (!file.is_open())
    {
        printf("Unable to open file path to shader:'%s'", path.c_str());
    }

    sourceCode << file.rdbuf();

    file.close();

    return sourceCode.str();
}

void Shader::_PopulateUniforms(void)
{
    S32 numberOfUniforms = -1;
    S32 length = 0;
    S32 size = 0;
    char name[256];
    GLenum type;

    Use();
    glGetProgramiv(_shaderHandle, GL_ACTIVE_UNIFORMS, &numberOfUniforms);

    for (S32 i = 0; i < numberOfUniforms; i++)
    {
        // Erase the name, basically filling the array with 0's
        memset(name, 0, sizeof(char) * 128);

        // Get the name of the next attribute in the list
        glGetActiveUniform(_shaderHandle, (GLuint)i, 128, &length, &size, &type, name);

        // Get the index of the next attribute in the list
        S32 uniformLocation = glGetUniformLocation(_shaderHandle, name);

        if (uniformLocation >= 0)
        {
            // TODO: Later, check for all possible types of uniforms
            // array []
            // block
            _uniforms[name] = uniformLocation;
        }
    }
    StopUse();
}

bool Shader::_CheckForCompileErrors(U32 shader)
{
    S32 success = 0;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        std::cout << "\n\n\n============= Shader Error Log:==================\n\n\n";
        char logs[1024];
        glGetShaderInfoLog(shader, 1024, NULL, logs);
        std::cout << "Shader failed to Compile." << std::endl
            << "\t" << logs << std::endl;

        return true;
    }
    return false;
}


void Shader::_CheckForUniform(string name)
{
    if (_uniforms.find(name) == _uniforms.end())
    {
        string msg = "No such uniform found. Name: ";
        msg += name;
        assert(1 && msg.c_str());
    }
}
