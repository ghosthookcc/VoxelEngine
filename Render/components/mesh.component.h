#ifndef MESH_COMPONENT_H
#define MESH_COMPONENT_H

#include "dynArray.h"

#include "staticChunkManager.component.h"
#include "staticVoxelGeometry.component.h"

typedef struct Mesh Mesh;
struct Mesh
{
  dynFloatArray* vertices; // a vertex is a single point
  dynUIntArray* edges; // an edge is a straight line segment connecting two vertices
                       // also knows as a indice
  dynFuncptrArray* functions;
  int (*getTriangleCount)(Mesh);
};

Mesh new_Mesh();

Mesh getMeshBlock();
Mesh getMeshFace(BlockFace face);

void updateMesh_PerlinSmooth(Mesh* self, Mesh other, int x, int y, int z);
void updateMesh_PerlinBlock(Mesh* self, Mesh other, int x, int y, int z);

int getTriangleCount(Mesh self);

void ComputeVerticesToIndices(dynFloatArray* vertices);

#endif
