#version 400

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in vec4 out_g_color[];
in vec2 out_g_uv[];

out vec4 out_f_color;
out vec2 out_f_uv;

uniform mat4 MVP;

void main()
{
  for(int i = 0; i < gl_in.length(); i++)
  {
    out_f_color = out_g_color[i];
    gl_Position = gl_in[i].gl_Position;
    EmitVertex();
  }
  EndPrimitive();
}
