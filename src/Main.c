#include "window.h"
#include "worldManager.component.h"

int physics_thread()
{
  LoadPlanetProperties();
  struct bodies bodylist = *GetBodyList();
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
