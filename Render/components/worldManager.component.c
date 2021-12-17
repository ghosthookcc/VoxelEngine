#include "worldManager.component.h"
#include <stdio.h>

void setup_world()
{
  generateFlatChunk();
  loadModelToVAO("../Resource Files/obj/suzanne.obj");
}
