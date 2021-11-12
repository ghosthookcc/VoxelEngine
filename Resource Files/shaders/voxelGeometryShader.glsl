#version 400

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;
in vec3 out_f_Color[];
flat out vec3 colors[3];
out vec3 coord;

for (int i = 0; i < 3; i++)
{
    colors[i] = out_f_Color[i];
}

for (int i = 0; i < 3; i++)
{
    coord = vec3(0.0f);
    coord[i] = 1.0;
    gl_Position = gl_in[i].gl_Position;
    EmitVertex();
}
