#version 330 core

layout (location=0) in vec2 position;
layout (location=1) in vec2 uvs;

uniform mat4 model;
uniform mat4 view;

out vec2 vertex_uvs;

void main()
{
    gl_Position = view * model * vec4(position, 0.0, 1.0);

    vertex_uvs = uvs;
}