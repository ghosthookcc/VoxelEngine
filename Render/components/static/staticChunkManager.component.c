#include "staticChunkManager.component.h"

#include "cameraManager.component.h"
#include "entityManager.component.h"

void generateChunk()
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
        temp_face = getMeshFace(BLOCK_BACK);
        temp_mesh.updateMesh(&temp_mesh, temp_face, x, y, (int)(z - 0.5f));

        temp_face = getMeshFace(BLOCK_LEFT);
        temp_mesh.updateMesh(&temp_mesh, temp_face, (int)(x - 0.5f), y, z);

        temp_face = getMeshFace(BLOCK_FRONT);
        temp_mesh.updateMesh(&temp_mesh, temp_face, x, y, (int)(z + 0.5f));

        temp_face = getMeshFace(BLOCK_TOP);
        temp_mesh.updateMesh(&temp_mesh, temp_face, x, (int)(y + 0.5f), z);

        temp_face = getMeshFace(BLOCK_RIGHT);
        temp_mesh.updateMesh(&temp_mesh, temp_face, (int)(x + 0.5f), y, z);

        temp_face = getMeshFace(BLOCK_BOTTOM);
        temp_mesh.updateMesh(&temp_mesh, temp_face, x, y, z);
      }
    }
  }

  printf("%i vertices loaded to VAO\n", temp_mesh.vertices->size);
  printf("%i triangles loaded to VAO\n\n", temp_mesh.getTriangleCount(temp_mesh));

  loadToVAO(temp_mesh);
}
