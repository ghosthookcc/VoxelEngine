#include "staticChunkManager.component.h"

#include "cameraManager.component.h"
#include "entityManager.component.h"

#include "configurations/config.h"

#include "dynArray.h"
#include "ghostymath.h"
#include "perlin.h"

void generateSmoothChunk()
{
  Mesh temp_block = getMeshBlock();
  Mesh temp_block_mesh = new_Mesh();

  dynFuncptrArray_AddBack(&temp_block_mesh.functions, updateMesh_PerlinSmooth);

  for(int x = 0; x < configurations.CHUNK_XYZ_SIZE; x++)
  {
    for(int y = 0; y < configurations.CHUNK_XYZ_SIZE; y++)
    {
      for(int z = 0; z < configurations.CHUNK_XYZ_SIZE; z++)
      {
        if(y == 0)
        {
          temp_block_mesh.functions->funcs[0](&temp_block_mesh, temp_block, x, y, z);
        }
      }
    }
  }

  //ComputeVerticesAsIndices(temp_mesh.vertices);

  loadToVAO(temp_block_mesh, new_vec3(0.0f, 0.0f, 0.0f));
}

void generateBlockChunk()
{
  Mesh temp_block = getMeshBlock();
  Mesh temp_block_mesh = new_Mesh();
  
  dynFuncptrArray_AddBack(&temp_block_mesh.functions, updateMesh_PerlinBlock);

  for(int x = 0; x < configurations.CHUNK_XYZ_SIZE; x++)
  {
    for(int y = 0; y < configurations.CHUNK_XYZ_SIZE; y++)
    {
      for(int z = 0; z < configurations.CHUNK_XYZ_SIZE; z++)
      {
        if(y == 0)
        {
          temp_block_mesh.functions->funcs[0](&temp_block_mesh, temp_block, x, y, z);
        }
      }
    }
  }

  //ComputeVerticesAsIndices(temp_mesh.vertices);

  loadToVAO(temp_block_mesh, new_vec3(0.0f, 0.0f, 0.0f));
}
