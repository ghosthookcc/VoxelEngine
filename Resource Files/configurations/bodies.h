#ifndef BODIES_H
#define BODIES_H

#include "vec3.h"

typedef struct body
{
  unsigned int bID;
  double radius;
  double mass;
  vec3 position;
  vec3 velocity;
} body;

struct bodies
{
  unsigned int size;
  body planets[6];
};

#endif
