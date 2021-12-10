#include "vec2.h"

vec2 new_vec2(float x, float y)
{
  vec2 construct;

  construct.x = x;
  construct.y = y;

  return construct;
}

ivec2 new_ivec2(int x, int y)
{
  ivec2 construct;

  construct.x = x;
  construct.y = y;

  return construct;
}

UByteVec2 new_UByteVec2(unsigned char x, unsigned char y)
{
  UByteVec2 construct;

  construct.x = x;
  construct.y = y;

  return construct;
}
