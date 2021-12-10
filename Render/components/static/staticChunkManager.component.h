#ifndef STATIC_CHUNK_MANAGER_COMPONENT_H
#define STATIC_CHUNK_MANAGER_COMPONENT_H

#define CHUNK_XYZ_SIZE 16

typedef struct TOF_Flag
{
  unsigned char exists : 1;
} TOF_Flag;

typedef enum BlockFace
{
  BLOCK_TOP,
  BLOCK_BOTTOM,
  BLOCK_FRONT,
  BLOCK_BACK,
  BLOCK_RIGHT,
  BLOCK_LEFT
} BlockFace;

static const int CHUNK_AREA = CHUNK_XYZ_SIZE * CHUNK_XYZ_SIZE;
static const int CHUNK_VOLUME = CHUNK_XYZ_SIZE * CHUNK_XYZ_SIZE * CHUNK_XYZ_SIZE;

#include <stdio.h>

#include "mesh.component.h"

#include "vec3.h"

void generateChunk();

#endif
