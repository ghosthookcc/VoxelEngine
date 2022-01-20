#include "worldManager.component.h"

void setup_world()
{
  //generateSmoothChunk();
  clock_t timed;
  timed = clock();
  generateSmoothChunk();
  timed = clock() - timed;
  double time_taken = ((double)timed/CLOCKS_PER_SEC);
  printf("smoothChunk of size [%d] took %f seconds to execute. . . \n", CHUNK_XYZ_SIZE, time_taken);
  //loadModelToVAO("../Resource Files/obj/suzanne.obj");
}
