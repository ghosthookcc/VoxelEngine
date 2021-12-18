#include "worldManager.component.h"

void setup_world()
{
  generateFlatChunk();
  loadModelToVAO("../Resource Files/obj/suzanne.obj");
}
