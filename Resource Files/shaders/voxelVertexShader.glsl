#version 400

in vec3 in_Color;
in vec3 in_Position;
in int in_FaceIndex;

flat out int out_FaceIndex;
flat out lowp vec3 out_Color;

uniform mat4 projViewMatrix;
uniform mat4 transformationMatrix;

uniform float voxelSize = 0.25;
uniform vec3 offset = vec3(0.0, 0.0, 0.0);

void main()
{
    gl_Position = projViewMatrix * transformationMatrix * vec4(in_Position * voxelSize + offset, 1.0f);
    out_FaceIndex = in_FaceIndex;
    out_Color = in_Color;
}
