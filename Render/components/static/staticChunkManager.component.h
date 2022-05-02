#ifndef STATIC_CHUNK_MANAGER_COMPONENT_H
#define STATIC_CHUNK_MANAGER_COMPONENT_H

#include <malloc.h>

#include "vec3.h"

typedef struct TOF_Flag
{
  unsigned char exists : 1;
} TOF_Flag;

typedef enum BlockFace
{
  FACE_TOP,
  FACE_BOTTOM,
  FACE_FRONT,
  FACE_BACK,
  FACE_RIGHT,
  FACE_LEFT
} BlockFace;

typedef enum BlockType
{
  BLOCK_AIR,
  BLOCK_DEFAULT
} BlockType;

#include "mesh.component.h"

void generateSmoothChunk();
void generateBlockChunk();

#endif
