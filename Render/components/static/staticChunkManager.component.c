#include "staticChunkManager.component.h"

#include "cameraManager.component.h"
#include "entityManager.component.h"

#include "ghostymath.h"
#include "perlin.h"
#include <stdio.h>

HeightMap generateHeightMap(int start, int max)
{
  //Mesh temp_face;
  //Mesh temp_mesh = new_Mesh();

  HeightMap new_HeightMap;
  new_HeightMap.HeightMap = new_dynFloatArray();

  return(new_HeightMap);
}

void generateChunk(int X, int Y, int Z)
{
  Mesh temp_face;
  Mesh temp_mesh = new_Mesh();

  double noiseValue;

  float tempY;
  for(float x = 0; x < CHUNK_XYZ_SIZE; x++)
  {
    for(float y = 0; y < CHUNK_XYZ_SIZE; y++)
    {
      for(float z = 0; z < CHUNK_XYZ_SIZE; z++)
      {
        noiseValue = GenerateFinalNoise3D(x, y, z, 8, 0.1, 3.0, 0);
        if(y == 0)
        {
          tempY = (float)(noiseValue);

          temp_face = getMeshFace(FACE_BACK);
          temp_mesh.updateMesh(&temp_mesh, temp_face, x, tempY, z);

          temp_face = getMeshFace(FACE_LEFT);
          temp_mesh.updateMesh(&temp_mesh, temp_face, x, tempY, z);

          temp_face = getMeshFace(FACE_FRONT);
          temp_mesh.updateMesh(&temp_mesh, temp_face, x, tempY, z);

          temp_face = getMeshFace(FACE_TOP);
          temp_mesh.updateMesh(&temp_mesh, temp_face, x, tempY, z);

          temp_face = getMeshFace(FACE_RIGHT);
          temp_mesh.updateMesh(&temp_mesh, temp_face, x, tempY, z);

          temp_face = getMeshFace(FACE_BOTTOM);
          temp_mesh.updateMesh(&temp_mesh, temp_face, x, tempY, z);
        }
      }
    }
  }

  loadToVAO(temp_mesh);
}
