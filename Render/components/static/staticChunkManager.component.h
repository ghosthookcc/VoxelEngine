#ifndef STATIC_CHUNK_MANAGER_COMPONENT_H
#define STATIC_CHUNK_MANAGER_COMPONENT_H

#define CHUNK_XYZ_SIZE 16

static const int CHUNK_AREA = CHUNK_XYZ_SIZE * CHUNK_XYZ_SIZE;
static const int CHUNK_VOLUME = CHUNK_XYZ_SIZE * CHUNK_XYZ_SIZE * CHUNK_XYZ_SIZE;

#include "mesh.component.h"

void testRenderChunk();

#endif
