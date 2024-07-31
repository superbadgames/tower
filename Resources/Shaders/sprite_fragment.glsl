#version 330 core
#extension GL_ARB_explicit_uniform_location : enable

out vec4 outputColor;

in vec2 texture_uvs;


uniform vec4 myColor;
uniform sampler2D spriteTexture;

void main()
{
   // outputColor = texture(spriteTexture, texture_uvs) * sprite_color;
   //vec4 copy = myColor;
   outputColor = myColor;
}