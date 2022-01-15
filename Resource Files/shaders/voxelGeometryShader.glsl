#version 400

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in vec4 out_g_Color[];
in int out_g_Enabled[];

out vec4 out_f_Color;

uniform mat4 MVP;

void main()
{
  for(int i = 0; i < gl_in.length(); i++)
  {
    out_f_Color = out_g_Color[i];
    gl_Position = gl_in[i].gl_Position;
    EmitVertex();
  }
  EndPrimitive();
}
