#ifndef MESH_COMPONENT_H
#define MESH_COMPONENT_H

#include "staticVoxelGeometry.component.h"

#include "dynArray.h"

typedef struct Mesh
{
  dynFloatArray* vertices; // a vertex is a single point
  dynUByteArray* edges; // an edge is a straight line segment connecting two vertices
                        // also knows as a indice
} Mesh;

Mesh new_Mesh();

#endif
