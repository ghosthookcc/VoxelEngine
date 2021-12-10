#include "worldManager.component.h"
#include <stdio.h>

void setup_world()
{
  generateChunk();
  loadModelToVAO("../Resource Files/obj/suzanne.obj");
}
