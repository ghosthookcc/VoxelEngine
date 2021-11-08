#version 400

layout (location = 0) in vec4 in_Position;

uniform vec3 offset;

uniform mat4 projViewMatrix;
uniform mat4 transformationMatrix;

void main()
{
	vec4 totalOffset = vec4(offset.x, offset.y, offset.z, 1.0f);
	gl_Position = projViewMatrix * transformationMatrix * (in_Position + totalOffset);
};
