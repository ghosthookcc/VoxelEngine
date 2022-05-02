#include "staticVoxelGeometry.component.h"

#include "dynArray.h"
#include "ghostymath.h"

/*
VoxelSet new_VoxelSet(ivec3 size)
{
    VoxelSet new_VoxelSet;

    int elemCount = size.x * size.y * size.z;

    new_VoxelSet.size = size;
    new_VoxelSet.colors = new_dynVec4Array();

    new_VoxelSet.colors->size = elemCount;
    new_VoxelSet.colors = realloc(new_VoxelSet.colors, sizeof(vec4) * new_VoxelSet.colors->size);

    for (int i = 0; i < elemCount; i++)
    {
      new_VoxelSet.colors->items[i] = new_vec4(0.0f, 0.0f, 0.0f, 0.0f);
    }

    unsigned char (*IsValidFunc)(ivec3, VoxelSet*) = IsValid;
    unsigned char (*IsSolidFunc)(ivec3, VoxelSet*) = IsSolid;
    vec4 (*AtFunc)(ivec3, VoxelSet*) = At;

    return(new_VoxelSet);
}

unsigned char IsValid(ivec3 index, VoxelSet* voxelRef)
{
  return index.x >= 0 && index.y >= 0 && index.z >= 0
      && index.x < voxelRef->size.x && index.y < voxelRef->size.y && index.z < voxelRef->size.z;
}

unsigned char IsSolid(ivec3 index, VoxelSet* voxelRef)
{
    return(IsValid(index, voxelRef) && At(index, voxelRef).x > 0.1f);
}

vec4 At(ivec3 index, VoxelSet* voxelRef)
{
    return voxelRef->colors->items[index.z * (voxelRef->size.x * voxelRef->size.y) + index.y * voxelRef->size.x + index.x];
}
*/

Mesh fast_sphere(float radius, int sectorCount, int stackCount)
{
  float x, y, z, xy;

  float sectorStep = (float)(2 * GHOSTYMATH_PI) / sectorCount;
  float stackStep = (float)(GHOSTYMATH_PI) / stackCount;
  float sectorAngle, stackAngle;

  Mesh fast_sphere_mesh = new_Mesh(sectorCount * stackCount * 3);
  for(int i = 0; i <= stackCount; ++i)
  {
    stackAngle = (float)(GHOSTYMATH_PI / 2) - i * stackStep;
    xy = radius * cosf(stackAngle);
    z = radius * sinf(stackAngle);

    for(int j = 0; j <= sectorCount; ++j)
    {
      sectorAngle = j * sectorStep;

      x = xy * cosf(sectorAngle);
      y = xy * sinf(sectorAngle) * 1.75f;

      dynFloatArray_AddVec3Values(&fast_sphere_mesh.vertices, new_vec3(x, y, z));
    }
  }

  //  indices
  //  k1--k1+1
  //  |  / |
  //  | /  |
  //  k2--k2+1
  unsigned int k1, k2;
  for(int i = 0; i < stackCount; ++i)
  {
    k1 = i * (sectorCount + 1);
    k2 = k1 + sectorCount + 1;

    for(int j = 0; j < sectorCount; ++j, ++k1, ++k2)
    {
      if(i != 0)
      {
        dynUIntArray_AddVec3Values(&fast_sphere_mesh.edges, new_uivec3(k1, k2, k1+1));
      }

      if(i != (stackCount-1))
      {
        dynUIntArray_AddVec3Values(&fast_sphere_mesh.edges, new_uivec3(k1+1, k2, k2+1));
      }
    }
  }
  return(fast_sphere_mesh);
}

Mesh trippy_sphere(int radius)
{
  int sectorcount = 100;
  int stackcount = 100;

  float x = 0.0f, y = 0.0f, z = 0.0f, xy = 0.0f;
  float sectorangle = 0.0f, stackangle = 0.0f;

  Mesh sphere_mesh = new_Mesh(sectorcount * stackcount * 3);

  float sectorstep = (float)(2.0 * GHOSTYMATH_PI / (double)(sectorcount));
  float stackstep = (float)(GHOSTYMATH_PI / (double)(stackcount));

  for(int i = 0; i < stackcount; i++)
  {
    stackangle = (float)(GHOSTYMATH_PI / 2.0) - ((float)i) * stackstep;
    xy = radius * cosf(stackangle);
    z = radius * sinf(stackangle);
    for(int ii = 0; ii < sectorcount; ii++)
    {
      sectorangle = ((float)ii) * sectorstep;

      x = xy * cosf(sectorangle);
      y = xy * sinf(sectorangle);

      dynFloatArray_AddVec3Values(&sphere_mesh.vertices, new_vec3(x,y,z));
    }
  }
  return(sphere_mesh);
}
