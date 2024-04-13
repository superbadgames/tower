#pragma once

#include "pch.h"
#include "Tower/framework.h"
#include "Tower/Rendering/Texture.hpp"
#include <unordered_map>

namespace Tower
{
    class TextureManager
    {
    public:
        TextureManager(void);

        ~TextureManager(void);

        void LoadTexture(U32 textureID, const string& filepath);

        void RegisterTexture(U32 textureID, p_Texture texture);

        p_Texture GetTexture(U32 textureID);

    private:
        std::unordered_map<U32, p_Texture> _textures;
    };
    typedef shared_ptr<TextureManager> p_TextureManager;
}