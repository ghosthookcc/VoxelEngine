#ifndef VEC4_H
#define VEC4_H

#include <malloc.h>

typedef struct
{
  float x;
  float y;
  float z;
  float w;
} vec4;

vec4 new_vec4(float x, float y, float z, float w);

#endif
