#version 330 core

out vec4 outputColor;

in vec2 texture_uvs;


uniform vec4 sprite_color;
uniform sampler2D spriteTexture;

void main()
{
  outputColor = texture(spriteTexture, texture_uvs) + (sprite_color * 0.0);
}