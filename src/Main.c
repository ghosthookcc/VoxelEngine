#include "window.h"
#include "worldManager.component.h"

int physics_thread()
{
  LoadPlanetProperties();
  struct bodies bodylist = *GetBodyList();
  while(1)
  {
    bodylist = ProcessPhysics(&bodylist);
    printf("    \r  Planets position (x, y, z) :: (%f, %f, %f) ; Planets velocity (x, y, z) :: (%f, %f, %f)", bodylist.planets[3].position.x, bodylist.planets[3].position.y, bodylist.planets[3].position.z,
                                                                                                        bodylist.planets[3].velocity.x, bodylist.planets[3].velocity.y, bodylist.planets[3].velocity.z);
  }

  //ProcessPhysics(GetBodyList());
  //ProcessPhysics(GetBodyList());

  return 86; //haha yes
}

int main()
{
  GH_InitWindow(physics_thread);
  return 0;
}
