#ifndef STATIC_VOXEL_GEOMETRY_COMPONENT_H
#define STATIC_VOXEL_GEOMETRY_COMPONENT_H

#include "mesh.component.h"

typedef struct PointVertex
{
  vec3 position;
  vec3 color;
  unsigned char enabledFaces;
} Voxel;

typedef struct VoxelSet
{
    ivec3 size;
    //dynVec4Array* colors;

    unsigned char (*IsValidFunc)(ivec3);
    unsigned char (*IsSolidFunc)(ivec3);
    vec4 (*AtFunc)(ivec3);
} VoxelSet;

VoxelSet new_VoxelSet();

unsigned char IsValid(ivec3 index, VoxelSet* voxelRef);
unsigned char IsSolid(ivec3 index, VoxelSet* voxelRef);
vec4 At(ivec3 index, VoxelSet* voxelRef);

struct Mesh fast_sphere(float radius, int sectorCount, int stackCount);

#endif
