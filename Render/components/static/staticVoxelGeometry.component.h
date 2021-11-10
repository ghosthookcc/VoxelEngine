#ifndef STATIC_VOXEL_GEOMETRY_COMPONENT_H
#define STATIC_VOXEL_GEOMETRY_COMPONENT_H

#include "vec3.h"

typedef struct Voxel
{
  vec3 position;
  unsigned int packedColor;
  unsigned char enabledFaces;
} Voxel;

#endif
