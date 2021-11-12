#include "staticVoxelGeometry.component.h"

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
