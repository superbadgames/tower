#pragma once

#include "pch.h"
#include "Tower/framework.h"


namespace Tower
{
    class Texture
    {
    public:
        Texture(void);

        Texture(const Texture& texture);

        Texture(U32 textureId, S32 width, S32 height);

        ~Texture(void);

        void Load(string filepath, bool generateMipMaps = true);

        void Bind(U32 texUnit = 0);

        void Unbind(void);

        inline GLuint GetTextureID(void) const { return _textureID; }

        inline S32 GetWidth(void) const { return _width; }

        inline S32 GetHeight(void) const { return _height; }

    private:
        GLuint _textureID;
        S32 _width;
        S32 _height;
    };
    typedef shared_ptr<Texture> p_Texture;
}