#ifndef VEC2_H
#define VEC2_H

typedef struct
{
  float x;
  float y;
} vec2;

typedef struct
{
  int x;
  int y;
} ivec2;

typedef struct
{
  unsigned char x;
  unsigned char y;
} UByteVec2;


vec2 new_vec2(float x, float y);

ivec2 new_ivec2(int x, int y);

UByteVec2 new_UByteVec2(unsigned char x, unsigned char y);

#endif
