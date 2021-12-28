#include "staticChunkManager.component.h"

#include "cameraManager.component.h"
#include "entityManager.component.h"

#include "perlin.h"
#include <stdio.h>

HeightMap generateHeightMap(int start, int max)
{
  Mesh temp_face;
  Mesh temp_mesh = new_Mesh();

  HeightMap new_HeightMap;
  new_HeightMap.HeightMap = new_dynFloatArray();

  return(new_HeightMap);
}

void generateFlatChunk()
{
  Mesh temp_face;
  Mesh temp_mesh = new_Mesh();

  for(int x = 0; x < CHUNK_XYZ_SIZE; x++)
  {
    for(int y = 0; y < CHUNK_XYZ_SIZE; y++)
    {
      for(int z = 0; z < CHUNK_XYZ_SIZE; z++)
      {
        if(y == 0)
        {
          temp_face = getMeshFace(FACE_BACK);
          temp_mesh.updateMesh(&temp_mesh, temp_face, x, y, z);

          temp_face = getMeshFace(FACE_LEFT);
          temp_mesh.updateMesh(&temp_mesh, temp_face, x, y, z);

          temp_face = getMeshFace(FACE_FRONT);
          temp_mesh.updateMesh(&temp_mesh, temp_face, x, y, z);

          temp_face = getMeshFace(FACE_TOP);
          temp_mesh.updateMesh(&temp_mesh, temp_face, x, y, z);

          temp_face = getMeshFace(FACE_RIGHT);
          temp_mesh.updateMesh(&temp_mesh, temp_face, x, y, z);

          temp_face = getMeshFace(FACE_BOTTOM);
          temp_mesh.updateMesh(&temp_mesh, temp_face, x, y, z);
        }
      }
    }
  }

  loadToVAO(temp_mesh);
}
