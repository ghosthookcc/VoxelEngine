#ifndef MESH_COMPONENT_H
#define MESH_COMPONENT_H

#include "staticChunkManager.component.h"
#include "staticVoxelGeometry.component.h"

#include "dynArray.h"

typedef struct Mesh Mesh;
struct Mesh
{
  dynFloatArray* vertices; // a vertex is a single point
  dynUIntArray* edges; // an edge is a straight line segment connecting two vertices
                       // also knows as a indice
  dynFloatArray* texcoords;
  dynFloatArray* normals;
  void (*updateMesh_PerlinSmooth)(Mesh*, Mesh, int, int, int);
  void (*updateMesh_PerlinBlock)(Mesh*, Mesh, int, int, int);
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
