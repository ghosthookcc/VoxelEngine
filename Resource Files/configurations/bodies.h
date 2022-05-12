#ifndef BODIES_H
#define BODIES_H

#include "vec3.h"

typedef struct body
{
  unsigned int bID;
  double radius;
  double mass;
  dvec3 position;
  dvec3 velocity;
} body;

struct bodies
{
  unsigned int size;
  body planets[6];
};

#endif
