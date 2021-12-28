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
  void (*updateMesh)(Mesh*, Mesh, float, float, float);
  int (*getTriangleCount)(Mesh);
};

Mesh new_Mesh();

Mesh getMeshFace(BlockFace face);

void updateMesh(Mesh* self, Mesh other, float x, float y, float z);

int getTriangleCount(Mesh self);

#endif
