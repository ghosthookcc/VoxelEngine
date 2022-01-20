#ifndef STATIC_CHUNK_MANAGER_COMPONENT_H
#define STATIC_CHUNK_MANAGER_COMPONENT_H

#include <malloc.h>

#include "dynArray.h"
#include "vec3.h"

#define CHUNK_XYZ_SIZE 128

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

typedef struct HeightMap
{
  BlockType blocks[CHUNK_XYZ_SIZE][CHUNK_XYZ_SIZE][CHUNK_XYZ_SIZE];
  dynFloatArray* HeightMap;
} HeightMap;


static const int CHUNK_AREA = CHUNK_XYZ_SIZE * CHUNK_XYZ_SIZE;
static const int CHUNK_VOLUME = CHUNK_XYZ_SIZE * CHUNK_XYZ_SIZE * CHUNK_XYZ_SIZE;

#include "mesh.component.h"

HeightMap new_HeightMap();

HeightMap generateHeightMap(int start, int max);

void generateSmoothChunk();
void generateBlockChunk();

#endif
