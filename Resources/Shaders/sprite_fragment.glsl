#version 330 core
out vec4 outputColor;

in vec2 vertex_uvs;

uniform sampler2D myTexture;



void main()
{
    outputColor = texture(myTexture, vertex_uvs);
}