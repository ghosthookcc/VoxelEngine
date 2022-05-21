#include "physics.component.h"
#define TIME_STEP 1.0f
/*
layer1
-------------
negTl   negTr
🠻       🠻
# # # # #
#       #
#       #
# # # # #
🠹       🠹
negBl   negBr

layer2
-------------
posTl   posTr
🠻       🠻
# # # # #
#       #
#       #
# # # # #
🠹       🠹
posBl   posBr
*/

struct blist ProcessPhysics(struct blist* bodylist)
{
  struct blist new_blist = *bodylist;
  for(unsigned int i = 0; i < bodylist->size; i++)
  {
    dvec3 accel1 = calcAccelLoop(bodylist->planets[i].position, *bodylist , bodylist->planets[i].bid);
    dvec3 deltavel = multiplyDVec3ByDouble(bodylist->planets[i].velocity, TIME_STEP);
    dvec3 deltaaccel1 = multiplyDVec3ByDouble(accel1, powf(TIME_STEP, 2.0));
    dvec3 new_pos_arg1 = addDVec3ByDVec3(bodylist->planets[i].position, deltavel);
    dvec3 new_pos_arg2 = divideDVec3ByDouble(deltaaccel1, 2.0);
    dvec3 new_pos = addDVec3ByDVec3(new_pos_arg1, new_pos_arg2);

    dvec3 accel2 = calcAccelLoop(new_pos, *bodylist, bodylist->planets[i].bid);
    dvec3 accel12 = multiplyDVec3ByDouble(divideDVec3ByDouble(addDVec3ByDVec3(accel1, accel2), 2.0), TIME_STEP);
    dvec3 new_vel = addDVec3ByDVec3(bodylist->planets[i].velocity, accel12);

    new_blist.planets[i].position = new_pos;
    new_blist.planets[i].velocity = new_vel;
  }

  //printf("Planets position (x, y, z) :: (%f, %f, %f) ; Planets velocity (x, y, z) :: (%f, %f, %f)\n", bodylist->planets[3].position.x, bodylist->planets[3].position.y, bodylist->planets[3].position.z,
  //                                                                                                    bodylist->planets[3].velocity.x, bodylist->planets[3].velocity.y, bodylist->planets[3].velocity.z);

  return(new_blist);
}
