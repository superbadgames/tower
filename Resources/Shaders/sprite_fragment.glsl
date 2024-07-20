#version 330 core
out vec4 outputColor;

in vec2 texture_uvs;

uniform sampler2D spriteTexture;

void main()
{
    outputColor = texture(spriteTexture, texture_uvs);
}