#include "window.h"

int physics_thread()
{
    struct bodies bodylist;
    LoadPlanetData(&bodylist);

    while(1)
    {
      ProcessPhysics(&bodylist);
    }

    return 86; //haha yes
}

int main()
{
  GH_InitWindow(physics_thread);
  return 0;
}
