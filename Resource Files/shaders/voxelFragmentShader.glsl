#version 400

precision highp float;
uniform vec2 u_resolution;  // Width and height of the shader
uniform float u_time;  // Time elapsed

in vec4 out_f_Color;

out vec4 frag_color;

void main()
{
	frag_color = out_f_Color;
};
