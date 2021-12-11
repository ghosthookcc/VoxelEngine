#include "vec3.h"

vec3 new_vec3(float x, float y, float z)
{
  vec3 construct;

  construct.x = x;
  construct.y = y;
  construct.z = z;

  return construct;
}

ivec3 new_ivec3(int x, int y, int z)
{
  ivec3 construct;

  construct.x = x;
  construct.y = y;
  construct.z = z;

  return construct;
}

uivec3 new_uivec3(unsigned int x, unsigned int y, unsigned int z)
{
  uivec3 construct;

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
