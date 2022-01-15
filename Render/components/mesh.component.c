#include "mesh.component.h"

#include "perlin.h"

#include <stdio.h>

Mesh new_Mesh()
{
  Mesh new_Mesh;
  new_Mesh.vertices = new_dynFloatArray();
  new_Mesh.edges    = new_dynUIntArray();
  new_Mesh.texcoords = new_dynFloatArray();
  new_Mesh.normals  = new_dynFloatArray();
  new_Mesh.updateMesh = updateMesh;
  new_Mesh.getTriangleCount = getTriangleCount;
  return(new_Mesh);
}

Mesh getMeshFace(BlockFace face)
{
  Mesh new_mesh = new_Mesh();

  float* faceVertices = malloc(sizeof(float) * 18);
  unsigned int* faceEdges = malloc(sizeof(unsigned int) * 6);
  float* faceNormals = malloc(sizeof(float) * 3);
  float* faceTexs = malloc(sizeof(float) * 3);

  switch(face)
  {
    case(FACE_TOP):
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
      fillArray(&faceEdges,
      (unsigned int[])
      {
        1, 5, 6,
        2, 1, 6
      });
      fillArray(&faceNormals,
      (float[])
      {
        0.0f, 1.0f, 0.0f
      });
      fillArray(&faceTexs,
      (float[])
      {
        0.0f,  1.0f,  0.0f
      });
      break;
    case(FACE_BOTTOM):
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
      fillArray(&faceEdges,
      (unsigned int[])
      {
        4, 0, 3, 7, 4, 3
      });
      fillArray(&faceNormals,
      (float[])
      {
        0.0f, -1.0f, 0.0f
      });
      fillArray(&faceTexs,
      (float[])
      {
        0.0f, -1.0f,  0.0f
      });
      break;
    case(FACE_FRONT):
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
      fillArray(&faceEdges,
      (unsigned int[])
      {
        0, 1, 2, 3, 0, 2
      });
      fillArray(&faceNormals,
      (float[])
      {
        0.0f, 0.0f, 1.0f
      });
      fillArray(&faceTexs,
      (float[])
      {
        0.0f,  0.0f,  1.0f
      });
      break;
    case(FACE_BACK):
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
      fillArray(&faceEdges,
      (unsigned int[])
      {
        6, 5, 4, 6, 4, 7
      });
      fillArray(&faceNormals,
      (float[])
      {
        0.0f, 0.0f, -1.0f
      });
      fillArray(&faceTexs,
      (float[])
      {
        0.0f,  0.0f, -1.0f
      });
      break;
    case(FACE_RIGHT):
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
      fillArray(&faceEdges,
      (unsigned int[])
      {
        3, 2, 6, 7, 3, 6
      });
      fillArray(&faceNormals,
      (float[])
      {
        1.0f, 0.0f, 0.0f
      });
      fillArray(&faceTexs,
      (float[])
      {
        1.0f,  0.0f,  0.0f
      });
      break;
    case(FACE_LEFT):
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
      fillArray(&faceEdges,
      (unsigned int[])
      {
        0, 1, 2,
        3, 0, 2
      });
      fillArray(&faceNormals,
      (float[])
      {
        -1.0f, 0.0f, 0.0f
      });
      fillArray(&faceTexs,
      (float[])
      {
        -1.0f,  0.0f,  0.0f
      });
      break;
  }

  new_mesh.vertices = new_DynFloatArrayFromFloatArray(faceVertices, 18);
  //new_mesh.edges = new_DynUIntArrayFromUIntArray(faceEdges, 6);
  new_mesh.normals = new_DynFloatArrayFromFloatArray(faceNormals, 3);
  new_mesh.texcoords = new_DynFloatArrayFromFloatArray(faceTexs, 3);

  return(new_mesh);
}

static float noiseValue;
void updateMesh(Mesh* self, Mesh other, int x, int y, int z)
{
  float tempX;
  float tempY;
  float tempZ;

  for(int i = 0; i < other.getTriangleCount(other); i++)
  {
    tempX = x * 0.5f;
    tempY = y * 0.5f;
    tempZ = z * 0.5f;

    noiseValue = GenerateFinalNoise3D(other.vertices->items[    i * 3] + tempX,
                                      other.vertices->items[1 + i * 3] + tempY,
                                      other.vertices->items[2 + i * 3] + tempZ,
                                      8, 0.1f, 4.0f, 0);

    dynFloatArray_AddBack(&self->vertices, other.vertices->items[    i * 3] + tempX);
    dynFloatArray_AddBack(&self->vertices, other.vertices->items[1 + i * 3] + tempY + fabsf(noiseValue));
    dynFloatArray_AddBack(&self->vertices, other.vertices->items[2 + i * 3] + tempZ);
  }

  for(int i = 0; i < other.normals->size; i++)
  {
    dynFloatArray_AddBack(&self->normals, other.normals->items[i]);
    dynFloatArray_AddBack(&self->texcoords, other.texcoords->items[i]);
  }
}

int getTriangleCount(Mesh self)
{
    return(self.vertices->size / 3);
}

dynFloatArray ComputeVerticesToIndices(dynFloatArray* vertices)
{
  float vert1;
  float vert2;
  for(int i = 0; i < vertices->size; i++)
  {
    vert1 = vertices->items[    i * 2];
    vert2 = vertices->items[1 + i * 2];
  }
  return(*vertices);
}
