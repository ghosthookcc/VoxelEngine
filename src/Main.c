#include "window.h"
#include "worldManager.component.h"

int physics_thread(struct bodies bodylist, struct bodies *shared_mem)
{
  LoadPlanetProperties();

  while(1)
  {
    bodylist = ProcessPhysics(&bodylist);
  }

  return 86; //haha yes
}

int main()
{
  GH_InitWindow(physics_thread);
  return 0;
}
