#version 400

layout (location = 0) in vec3 in_v_Position;
layout (location = 1) in vec4 in_v_Color;
layout (location = 2) in int in_v_EnabledFaces;

out vec4 out_f_Color;

uniform vec3 offset = vec3(0.0f, 0.0f, 0.0f);

uniform mat4 MVP;

void main()
{
	gl_Position = MVP * vec4(in_v_Position + offset, 1.0f);

  out_f_Color = in_v_Color;
};
