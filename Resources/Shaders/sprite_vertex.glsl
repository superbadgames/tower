#version 330 core
#extension GL_ARB_explicit_uniform_location : enable

layout (location=0) in vec2 position;
layout (location=1) in vec2 uvs;

out vec2 texture_uvs;

uniform vec3 testing_uniform;

void main()
{
    gl_Position = vec4(testing_uniform, 1.0) + vec4(position.x, position.y, 0.0, 1.0);
    texture_uvs = uvs;
}