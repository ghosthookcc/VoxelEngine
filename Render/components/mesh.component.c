#include "mesh.component.h"

#include <stdio.h>

Mesh new_Mesh()
{
  Mesh new_Mesh;
  new_Mesh.vertices = new_dynFloatArray();
  new_Mesh.edges    = new_dynUByteArray();
  new_Mesh.updateMesh = updateMesh;
  new_Mesh.getTriangleCount = getTriangleCount;
  return(new_Mesh);
}

Mesh getMeshFace(BlockFace face)
{
  Mesh new_mesh = new_Mesh();

  float* faceVertices = malloc(sizeof(float) * 18);
  unsigned char faceEdges[6] = { 0, 1, 2, 3, 4, 5 };

  switch(face)
  {
    case(BLOCK_TOP):
      fillArray(&faceVertices,
      (float[])
      {
        -0.5f,  0.5f, -0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f
      });
      break;
    case(BLOCK_BOTTOM):
      fillArray(&faceVertices,
      (float[])
      {
        -0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f
      });
      break;
    case(BLOCK_FRONT):
      fillArray(&faceVertices,
      (float[])
      {
        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f
      });
      break;
    case(BLOCK_BACK):
      fillArray(&faceVertices,
      (float[])
      {
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f
      });
      break;
    case(BLOCK_RIGHT):
      fillArray(&faceVertices,
      (float[])
      {
        0.5f,  0.5f,  0.5f,
        0.5f,  0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, -0.5f,  0.5f,
        0.5f,  0.5f,  0.5f
      });
      break;
    case(BLOCK_LEFT):
      fillArray(&faceVertices,
      (float[])
      {
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f
      });
      break;
  }

  new_mesh.vertices = new_DynFloatArrayFromFloatArray(faceVertices, 18);
  new_mesh.edges = new_DynUByteArrayFromUByteArray(faceEdges, 6);

  return(new_mesh);
}

void updateMesh(Mesh* self, Mesh other, int x, int y, int z)
{
  for(int i = 0; i < other.getTriangleCount(other); i++)
  {
    dynFloatArray_AddBack(&self->vertices, other.vertices->items[    i * 3] + x);
    dynFloatArray_AddBack(&self->vertices, other.vertices->items[1 + i * 3] + y);
    dynFloatArray_AddBack(&self->vertices, other.vertices->items[2 + i * 3] + z);
  }
}

int getTriangleCount(Mesh self)
{
    return(self.vertices->size / 3);
}
