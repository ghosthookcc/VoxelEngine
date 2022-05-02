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

void ProcessPhysics(Entity* Entity)
{
  struct bodies new_bodylist;

  for(unsigned int i = 0; i < bodylist.size; i++)
  {
    vec3 acceleration_1 = calcAccelLoop(bodylist.planets[i].position, bodylist.planets[i].bID);
    vec3 new_position = addVec3ByVec3(
                                      addVec3ByVec3(bodylist.planets[i].position, bodylist.planets[i].velocity),
                                      divideVec3(acceleration_1, 2.0f)
                                     );

    vec3 acceleration_2 = calcAccelLoop(new_position, bodylist.planets[i].bID);
    vec3 new_velocity = addVec3ByVec3(
                                      bodylist.planets[i].velocity,
                                      divideVec3(addVec3ByVec3(acceleration_1, acceleration_2), 2.0f)
                                      );
  }
}
