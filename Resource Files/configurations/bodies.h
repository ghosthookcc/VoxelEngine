#ifndef BODIES_H
#define BODIES_H

#include "vec3.h"

typedef struct body
{
  unsigned int bID;
  float radius;
  float mass;
  vec3 position;
  vec3 velocity;
} body;

struct bodies
{
  body planets[6];
  unsigned int size;
};
struct bodies bodylist;

#endif
