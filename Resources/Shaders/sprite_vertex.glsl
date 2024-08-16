#version 330 core

layout (location=0) in vec2 position;
layout (location=1) in vec2 uvs;

out vec2 texture_uvs;

uniform mat4 model;
// View = projectMatrix * cameraViewMatrix
uniform mat4 view;

void main()
{
    gl_Position = view * model * vec4(position.x, position.y, 0.0, 1.0);
    texture_uvs = uvs;
}