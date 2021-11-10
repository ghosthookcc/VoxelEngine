#version 400

uniform lowp vec3 in_Color;

void main()
{
	gl_FragColor = vec4(in_Color, 1.0f);
}
