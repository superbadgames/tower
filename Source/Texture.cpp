#include "pch.h"
#include "Tower/Rendering/Texture.hpp"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif
#include <stb_image.h>

using namespace Tower;

Texture::Texture(void) :
    _textureID(0),
    _width(0),
    _height(0)
{
    glGenTextures(1, &_textureID);
}

Texture::Texture(const Texture& texture) :
    _textureID(texture.GetTextureID()),
    _width(texture.GetWidth()),
    _height(texture.GetHeight())
{

}

Texture::Texture(U32 textureId, S32 width, S32 height) :
    _textureID(textureId),
    _width(width),
    _height(height)
{

}

Texture::~Texture(void)
{
    // ClearTexture();
    glDeleteTextures(1, &_textureID);
}

void Texture::Load(string filepath, bool generateMipMaps)
{
    // No need to save this, but it's required for the fuction call
    S32 colorChannels;
    unsigned char* imageData = stbi_load(filepath.c_str(), &_width, &_height, &colorChannels, 0);

    if (!imageData)
    {
        string msg = "Unable to load texture. Filepath : " + filepath;
        assert(msg.c_str());
    }

    glBindTexture(GL_TEXTURE_2D, _textureID);

    // TODO: Make both the wrap and filtering methods params that are passed into load, so its configurable at runtime.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

    if (generateMipMaps)
    {
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(imageData);
}

void Texture::Bind(U32 texUnit)
{
    glActiveTexture(GL_TEXTURE0 + texUnit);
    glBindTexture(GL_TEXTURE_2D, _textureID);
}

void Texture::Unbind(void)
{
    glActiveTexture(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}
