#include "worldManager.component.h"

#include "configurations/config.h"

#include <inttypes.h>

void LoadPlanetData(struct blist bodylist)
{
  Mesh sphere = new_Mesh();
  for(unsigned int PlanetIterator = 0; PlanetIterator < bodylist.size; PlanetIterator++)
  {
    sphere = fast_sphere(5.0f, 100, 100);
    loadToVAO(sphere, dvec3ToVec3(bodylist.planets[PlanetIterator].position));
  }
}

void setup_world(struct blist bodylist)
{
  LARGE_INTEGER diff;
  LARGE_INTEGER timeNow, timePrev;
  LARGE_INTEGER Frequency;

  QueryPerformanceFrequency(&Frequency);

  QueryPerformanceCounter(&timeNow);

  if(configurations.terrain_render == 1)
  {
    if(configurations.blocky_render == 0)
    {
      generateSmoothChunk();
    }
    else
    {
      generateBlockChunk();
    }
  }
  LoadPlanetData(bodylist);

  QueryPerformanceCounter(&timePrev);

  diff.QuadPart = timePrev.QuadPart - timeNow.QuadPart;
  diff.QuadPart *= 1000000;
  diff.QuadPart /= Frequency.QuadPart;

  printf("Chunk of size [%i] %"PRId64" milliseconds", configurations.CHUNK_XYZ_SIZE, diff.QuadPart / 1000);

  if(configurations.model_render == 1)
    loadModelToVAO("../Resource Files/obj/suzanne.obj");
}
