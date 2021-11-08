#include "mesh.component.h"

Mesh new_Mesh()
{
  Mesh new_Mesh;
  new_Mesh.vertices = new_dynFloatArray();
  new_Mesh.edges    = new_dynUByteArray();
  return(new_Mesh);
}
