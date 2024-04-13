#version 330 core
out vec4 outputColor;

in vec2 vertex_uvs;

uniform sampler2D myTexture;
uniform vec4 object_color;
uniform vec4 light_color;



void main()
{
    outputColor = (light_color * object_color) * texture(myTexture, vertex_uvs);
}