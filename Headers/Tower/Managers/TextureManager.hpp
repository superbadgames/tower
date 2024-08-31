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

        ~TextureManager(void);

        static shared_ptr<TextureManager> Instance(void);

        void LoadTexture(U32 textureID, const string& filepath);

        void RegisterTexture(U32 textureID, p_Texture texture);

        p_Texture GetTexture(U32 textureID);

    private:
        static shared_ptr<TextureManager> _instance;
        std::unordered_map<U32, p_Texture> _textures;

        TextureManager(void);
    };
    typedef shared_ptr<TextureManager> p_TextureManager;
}