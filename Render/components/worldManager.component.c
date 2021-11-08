#include "worldManager.component.h"

void setup_world()
{
  Mesh testmesh = new_Mesh();
  dynFloatArray_AddVec3Values(&testmesh.vertices, new_vec3(0.0f, 0.5f, -0.5f));
  dynFloatArray_AddVec3Values(&testmesh.vertices, new_vec3(-0.5f, 0.0f, -0.5f));
  dynFloatArray_AddVec3Values(&testmesh.vertices, new_vec3(0.5f, 0.0f, -0.5f));

  dynFloatArray_AddVec3Values(&testmesh.vertices, new_vec3(0.0f, 1.5f, -0.5f));
  dynFloatArray_AddVec3Values(&testmesh.vertices, new_vec3(-1.5f, 0.0f, -0.5f));
  dynFloatArray_AddVec3Values(&testmesh.vertices, new_vec3(1.5f, 0.0f, -0.5f));

  dynUByteArray_AddVec3Values(&testmesh.edges, new_UByteVec3(0, 1, 2));
  dynUByteArray_AddVec3Values(&testmesh.edges, new_UByteVec3(3, 4, 5));
  loadToVAO(testmesh);
}
