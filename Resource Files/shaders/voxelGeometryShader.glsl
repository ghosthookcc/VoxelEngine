#version 400

layout(points) in;
layout(triangle_strip, max_vertices = 12) out;

flat in lowp vec3 in_Colors[];
flat in int in_EnabledFaces[];

flat out lowp vec3 out_Color;

uniform mat4 projViewMatrix;
uniform mat4 transformationMatrix;

uniform float voxelSize = 0.25;

void AddQuad(vec4 center, vec4 dy, vec4 dx)
{
  out_Color = in_Color[0];
  gl_Position = center + (dx - dy);
  EmitVertex();

  out_Color = in_Color[0];
  gl_Position = center + (-dx - dy);
  EmitVertex();

  out_Color = in_Color[0];
  gl_Position = center + (dx + dy);
  EmitVertex();

  out_Color = in_Color[0];
  gl_Position = center + (-dx + dy);
  EmitVertex();

  EndPrimitive();
}

bool IsCulled(vec4 normal)
{
  return(normal.z > 0);
}

void main()
{
  vec4 center = gl_in[0].gl_Position;

  vec4 dx = (projViewMatrix * transformationMatrix)[0] / 2.0f * voxelSize;
  vec4 dy = (projViewMatrix * transformationMatrix)[1] / 2.0f * voxelSize;
  vec4 dz = (projViewMatrix * transformationMatrix)[2] / 2.0f * voxelSize;

  if ((in_EnabledFaces[0] & 0x01) != 0 && !IsCulled(dx))
    AddQuad(center + dx, dy, dz);

  if ((in_EnabledFaces[0] & 0x02) != 0 && !IsCulled(-dx))
    AddQuad(center - dx, dz, dy);

  if ((in_EnabledFaces[0] & 0x04) != 0 && !IsCulled(dy))
    AddQuad(center + dy, dz, dx);

  if ((in_EnabledFaces[0] & 0x08) != 0 && !IsCulled(-dy))
    AddQuad(center - dy, dx, dz);

  if ((in_EnabledFaces[0] & 0x10) != 0 && !IsCulled(dz))
    AddQuad(center + dz, dx, dy);

  if ((in_EnabledFaces[0] & 0x20) != 0 && !IsCulled(-dz))
    AddQuad(center - dz, dy, dx);
}
