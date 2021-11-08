#include "vec4.h"

vec4 new_vec4(float x, float y, float z, float w)
{
  vec4 construct;

  construct.x = x;
  construct.y = y;
  construct.z = z;
  construct.w = w;

  return construct;
}
