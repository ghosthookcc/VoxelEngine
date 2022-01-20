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

void generateSmoothChunk()
{
  Mesh temp_block = getMeshBlock();
  Mesh temp_block_mesh = new_Mesh();

  for(int x = 0; x < CHUNK_XYZ_SIZE; x++)
  {
    for(int y = 0; y < CHUNK_XYZ_SIZE; y++)
    {
      for(int z = 0; z < CHUNK_XYZ_SIZE; z++)
      {
        if(y == 0)
        {
          temp_block_mesh.updateMesh_PerlinSmooth(&temp_block_mesh, temp_block, x, y, z);
        }
      }
    }
  }

  //ComputeVerticesAsIndices(temp_mesh.vertices);

  loadToVAO(temp_block_mesh);
}

void generateBlockChunk()
{
  Mesh temp_block;
  Mesh temp_block_mesh = new_Mesh();

  for(int x = 0; x < CHUNK_XYZ_SIZE; x++)
  {
    for(int y = 0; y < CHUNK_XYZ_SIZE; y++)
    {
      for(int z = 0; z < CHUNK_XYZ_SIZE; z++)
      {
        if(y == 0)
        {
          temp_block = getMeshBlock();
          temp_block_mesh.updateMesh_PerlinBlock(&temp_block_mesh, temp_block, x, y, z);
        }
      }
    }
  }

  //ComputeVerticesAsIndices(temp_mesh.vertices);

  loadToVAO(temp_block_mesh);
}
