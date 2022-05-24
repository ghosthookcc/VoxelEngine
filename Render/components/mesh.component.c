#include "mesh.component.h"

#include "configurations/config.h"

#include "perlin.h"

Mesh new_Mesh()
{
  Mesh new_Mesh;
  new_Mesh.vertices = new_dynFloatArray();
  new_Mesh.edges    = new_dynUIntArray();
  new_Mesh.texcoords = new_dynFloatArray();
  //new_Mesh.normals  = new_dynFloatArray();
  new_Mesh.functions = new_dynFuncptrArray();
  new_Mesh.getTriangleCount = getTriangleCount;
  return(new_Mesh);
}

Mesh getMeshBlock()
{
    Mesh tmp_Mesh = new_Mesh();

    float* blockVertices = malloc(sizeof(float) * 108);
    fillArray(&blockVertices,
    (float[])
    {
      // Front face
      -0.5f, -0.5f,  0.5f,
       0.5f, -0.5f,  0.5f,
       0.5f,  0.5f,  0.5f,
       0.5f,  0.5f,  0.5f,
      -0.5f,  0.5f,  0.5f,
      -0.5f, -0.5f,  0.5f,

      // Back face
      -0.5f, -0.5f, -0.5f,
       0.5f, -0.5f, -0.5f,
       0.5f,  0.5f, -0.5f,
       0.5f,  0.5f, -0.5f,
      -0.5f,  0.5f, -0.5f,
      -0.5f, -0.5f, -0.5f,

      // Left face
      -0.5f,  0.5f,  0.5f,
      -0.5f,  0.5f, -0.5f,
      -0.5f, -0.5f, -0.5f,
      -0.5f, -0.5f, -0.5f,
      -0.5f, -0.5f,  0.5f,
      -0.5f,  0.5f,  0.5f,

      // Right face
      0.5f,  0.5f,  0.5f,
      0.5f,  0.5f, -0.5f,
      0.5f, -0.5f, -0.5f,
      0.5f, -0.5f, -0.5f,
      0.5f, -0.5f,  0.5f,
      0.5f,  0.5f,  0.5f,

      // Top face
      -0.5f,  0.5f, -0.5f,
      0.5f,  0.5f, -0.5f,
      0.5f,  0.5f,  0.5f,
      0.5f,  0.5f,  0.5f,
      -0.5f,  0.5f,  0.5f,
      -0.5f,  0.5f, -0.5f,

      // Bottom face
      -0.5f, -0.5f, -0.5f,
      0.5f, -0.5f, -0.5f,
      0.5f, -0.5f,  0.5f,
      0.5f, -0.5f,  0.5f,
      -0.5f, -0.5f,  0.5f,
      -0.5f, -0.5f, -0.5f
    });
    tmp_Mesh.vertices = new_DynFloatArrayFromFloatArray(blockVertices, 108);

    float* blockTexs = malloc(sizeof(float) * 8);
    fillArray(&blockTexs,
    (float[])
    {
      0.0f, 0.0f,  // bottom left of texture
      1.0f, 0.0f,  // bottom right
      1.0f, 1.0f,  // top right
      0.0f, 1.0f   // top left
    });
    tmp_Mesh.texcoords = new_DynFloatArrayFromFloatArray(blockTexs, 8);

    return(tmp_Mesh);
}

Mesh getMeshFace(BlockFace face)
{
  Mesh tmp_Mesh = new_Mesh();

  float* faceVertices = malloc(sizeof(float) * 18);
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
      fillArray(&faceNormals,
      (float[])
      {
        0.0f, 0.5f, 0.0f
      });
      fillArray(&faceTexs,
      (float[])
      {
        0.0f,  0.5f,  0.0f
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
      fillArray(&faceNormals,
      (float[])
      {
        0.0f, -0.5f, 0.0f
      });
      fillArray(&faceTexs,
      (float[])
      {
        0.0f, -0.5f,  0.0f
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
      fillArray(&faceNormals,
      (float[])
      {
        0.0f, 0.0f, 0.5f
      });
      fillArray(&faceTexs,
      (float[])
      {
        0.0f,  0.0f,  0.5f
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
      fillArray(&faceNormals,
      (float[])
      {
        0.0f, 0.0f, -0.5f
      });
      fillArray(&faceTexs,
      (float[])
      {
        0.0f,  0.0f, -0.5f
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
      fillArray(&faceNormals,
      (float[])
      {
        0.5f, 0.0f, 0.0f
      });
      fillArray(&faceTexs,
      (float[])
      {
        0.5f,  0.0f,  0.0f
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
      fillArray(&faceNormals,
      (float[])
      {
        -0.5f, 0.0f, 0.0f
      });
      fillArray(&faceTexs,
      (float[])
      {
        -0.5f,  0.0f,  0.0f
      });
      break;
  }

  tmp_Mesh.vertices = new_DynFloatArrayFromFloatArray(faceVertices, 18);
  //tmp_Mesh.edges = new_DynUIntArrayFromUIntArray(faceEdges, 6);
  //tmp_Mesh.normals = new_DynFloatArrayFromFloatArray(faceNormals, 3);
  //tmp_Mesh.texcoords = new_DynFloatArrayFromFloatArray(faceTexs, 3);

  return(tmp_Mesh);
}

static float noiseValue;
static float prevNoiseValue = 0.0f;
void updateMesh_PerlinSmooth(Mesh* self, Mesh other, int x, int y, int z)
{
  float step_size = 0.5f;
  float tempX;
  float tempY;
  float tempZ;
  int triangleCount = other.getTriangleCount(other);
  float centerX = ((x + (step_size * triangleCount)) - x);
  float centerY = ((y + (step_size * triangleCount)) - y);
  float centerZ = ((z + (step_size * triangleCount)) - z);


  for(int i = 0; i < triangleCount; i++)
  {
    tempX = x + step_size;
    tempY = y + step_size;
    tempZ = z + step_size;

    noiseValue = GenerateFinalNoise3D(other.vertices->items[    i * 3] + tempX,
                                      other.vertices->items[1 + i * 3] + tempY,
                                      other.vertices->items[2 + i * 3] + tempZ ,
                                      8, 0.1f, 2.0f, 0);

    dynFloatArray_AddBack(&self->vertices, other.vertices->items[    i * 3] + tempX - centerX);
    dynFloatArray_AddBack(&self->vertices, other.vertices->items[1 + i * 3] + (fabsf(noiseValue) - (fabsf(noiseValue) - y) / 2));
    dynFloatArray_AddBack(&self->vertices, other.vertices->items[2 + i * 3] + tempZ - centerZ);
  }
}

void updateMesh_PerlinBlock(Mesh* self, Mesh other, int x, int y, int z)
{
  float step_size = 0.5f;

  float initX = x;
  float initY = y;
  float initZ = z;
  int trianglecount = other.getTriangleCount(other);
  float centerX = (x * (step_size * trianglecount) - initX) / 2;
  float centerY = (y * (step_size * trianglecount) - initY) / 2;
  float centerZ = (z * (step_size * trianglecount) - initZ) / 2;

  float tempX;
  float tempY;
  float tempZ;

  for(int i = 0; i < trianglecount; i++)
  {
    tempX = x + step_size;
    tempY = y + step_size;
    tempZ = z + step_size;

    noiseValue = GenerateFinalNoise3D((float)x,
                                      (float)y,
                                      (float)z,
                                      8, 0.1f, 2.0f, 0);

    dynFloatArray_AddBack(&self->vertices, other.vertices->items[    i * 3] + tempX - centerX);
    dynFloatArray_AddBack(&self->vertices, other.vertices->items[1 + i * 3] + fabsf(tempY - noiseValue) - centerY);
    dynFloatArray_AddBack(&self->vertices, other.vertices->items[2 + i * 3] + tempZ - centerZ);
  }
}

int getTriangleCount(Mesh self)
{
    return(self.vertices->size / 3);
}

void ComputeVerticesToIndices(dynFloatArray* vertices)
{
  float vert1;
  float vert2;
  for(int i = 0; i < vertices->size; i++)
  {
    vert1 = vertices->items[    i * 2];
    vert2 = vertices->items[1 + i * 2];
  }
}
