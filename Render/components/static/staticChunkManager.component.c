#include "staticChunkManager.component.h"

#include "cameraManager.component.h"
#include "entityManager.component.h"

HeightMap generateHeightMap(int start, int max)
{
  Mesh temp_face;
  Mesh temp_mesh = new_Mesh();

  HeightMap new_HeightMap;

  return(new_HeightMap);
}

void generateFlatChunk()
{
  Mesh temp_face;
  Mesh temp_mesh = new_Mesh();

  TOF_Flag blocks[CHUNK_XYZ_SIZE][CHUNK_XYZ_SIZE][CHUNK_XYZ_SIZE];
  for(unsigned int x = 0; x < CHUNK_XYZ_SIZE; x++)
  {
    for(unsigned int y = 0; y < CHUNK_XYZ_SIZE; y++)
    {
      for(unsigned int z = 0; z < CHUNK_XYZ_SIZE; z++)
      {
        if (y == 0)
        {
          blocks[x][y][z].exists = 1;
        }
        else
        {
          blocks[x][y][z].exists = 0;
        }

        if(!blocks[x][y][z].exists) continue;
        temp_face = getMeshFace(FACE_BACK);
        temp_mesh.updateMesh(&temp_mesh, temp_face, x, y, (int)(z - 0.5f));

        temp_face = getMeshFace(FACE_LEFT);
        temp_mesh.updateMesh(&temp_mesh, temp_face, (int)(x - 0.5f), y, z);

        temp_face = getMeshFace(FACE_FRONT);
        temp_mesh.updateMesh(&temp_mesh, temp_face, x, y, (int)(z + 0.5f));

        temp_face = getMeshFace(FACE_TOP);
        temp_mesh.updateMesh(&temp_mesh, temp_face, x, (int)(y + 0.5f), z);

        temp_face = getMeshFace(FACE_RIGHT);
        temp_mesh.updateMesh(&temp_mesh, temp_face, (int)(x + 0.5f), y, z);

        temp_face = getMeshFace(FACE_BOTTOM);
        temp_mesh.updateMesh(&temp_mesh, temp_face, x, y, z);
      }
    }
  }

  loadToVAO(temp_mesh);
}
