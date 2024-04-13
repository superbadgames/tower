#include "pch.h"
#include "Tower/Managers/TextureManager.hpp"

using namespace Tower;

TextureManager::TextureManager(void):
    _textures()
{

}

TextureManager::~TextureManager(void)
{
    _textures.clear();
}

void TextureManager::LoadTexture(U32 textureID, const string& filepath)
{
    if (_textures.find(textureID) != _textures.end())
    {
        string msg = "Error! TextureManager::LoadTexture called with duplicate texture. Id = " + textureID;
        msg = msg + "\nAt filepath = " + filepath;
        assert(1 && msg.c_str());
    }

    p_Texture texture = std::make_shared<Texture>();
    texture->Load(filepath);

    _textures[textureID] = texture;
}

void TextureManager::RegisterTexture(U32 textureID, p_Texture texture)
{
    if (_textures.find(textureID) != _textures.end())
    {
        string msg = "Error! TextureManager::LoadTexture called with duplicate texture. Id = " + textureID;
        assert(1 && msg.c_str());
    }
    _textures[textureID] = texture;
}

p_Texture TextureManager::GetTexture(U32 textureID)
{
    if (_textures.find(textureID) == _textures.end())
    {
        string msg = "Error! TextureManager::GetTexture failed to find a texture with ID " + textureID;
        assert(1 && msg.c_str());
    }

    return _textures[textureID];
}