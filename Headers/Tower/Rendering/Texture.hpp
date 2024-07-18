#pragma once

#include "pch.h"
#include "Tower/framework.h"


namespace Tower
{
    class Texture
    {
    public:
        Texture(void);

        ~Texture(void);

        void Load(string filepath, bool generateMipMaps = true);

        void Bind(U32 texUnit = 0);

        void Unbind(void);

    private:
        GLuint _textureID;
        string _type;
        S32 _width;
        S32 _height;
        S32 _colorChannels;
    };
    typedef shared_ptr<Texture> p_Texture;
}