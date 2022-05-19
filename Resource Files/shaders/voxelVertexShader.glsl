#version 400

layout (location = 0) in vec3 in_v_Position;
layout (location = 1) in vec4 in_v_Color;
layout (location = 2) in vec3 in_v_Normal;
layout (location = 3) in vec2 in_v_Uv;

out vec4 out_g_color;
out vec2 out_g_uv;

out vec2 screenPos;

uniform float ambient = 1.0f;
uniform vec3 offset = vec3(0.0f, 0.0f, 0.0f);

uniform mat4 MVP;

const vec3 dir = vec3(1,2,3);

void main()
{
	screenPos = in_v_Position.xy;
	float diffuse  = 0.8f * max(dot(vec3(0.0f, 0.0f, 0.0f), normalize(dir * in_v_Normal)), 0.0);

	gl_Position = MVP * vec4(in_v_Position + offset, 1.0f);

	out_g_color = (ambient + diffuse) * in_v_Color;
	out_g_uv = in_v_Uv;
};
