#version 330
in vec2 text_uvs;

out vec4 color;

uniform sampler2D glyph;
uniform vec3 text_color;

void main()
{
    vec4 sampledColors = vec4(1.0, 1.0, 1.0, texture(glyph, text_uvs).r);
    color = vec4(text_color, 1.0) * sampledColors;
}
