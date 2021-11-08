#include "vec3.h"

vec3 new_vec3(float x, float y, float z)
{
  vec3 construct;

  construct.x = x;
  construct.y = y;
  construct.z = z;

  return construct;
}

UByteVec3 new_UByteVec3(unsigned char x, unsigned char y, unsigned char z)
{
  UByteVec3 construct;

  construct.x = x;
  construct.y = y;
  construct.z = z;

  return construct;
}
