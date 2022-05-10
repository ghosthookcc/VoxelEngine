#include "physics.component.h"

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

void ProcessPhysics(struct bodies* bodylist)
{
  struct bodies new_bodylist = *bodylist;

  body sel_body;

  for(unsigned int i = 0; i < bodylist->size; i++)
  {
    sel_body = bodylist->planets[i];
    vec3 acceleration_1 = calcAccelLoop(sel_body.position, bodylist, sel_body.bID);
    vec3 new_position = addVec3ByVec3(
                                      addVec3ByVec3(sel_body.position, sel_body.velocity),
                                      divideVec3(acceleration_1, 2.0f)
                                     );

    vec3 acceleration_2 = calcAccelLoop(new_position, bodylist, sel_body.bID);
    vec3 new_velocity = addVec3ByVec3(
                                      sel_body.velocity,
                                      divideVec3(addVec3ByVec3(acceleration_1, acceleration_2), 2.0f)
                                      );

    new_bodylist.planets[i].position = new_position;
    new_bodylist.planets[i].velocity = new_velocity;

  }
  *bodylist = new_bodylist;

  printf("Planets position (x, y, z) :: (%f, %f, %f) ; Planets velocity (x, y, z) :: (%f, %f, %f)\n", bodylist->planets[3].position.x, bodylist->planets[3].position.y, bodylist->planets[3].position.z,
  bodylist->planets[3].velocity.x, bodylist->planets[3].velocity.y, bodylist->planets[3].velocity.z);
}
