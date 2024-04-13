# version 330 core
layout (location = 0) in vec4 vertex; // Vertext position and UV coords for the glyph
out vec2 text_uvs;

uniform mat4 projection;

void main()
{
    gl_Position = projection * vec4(vertex.xy, 0.0, 1.0);
    text_uvs = vertex.zw;
}
