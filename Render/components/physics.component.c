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

struct bodies ProcessPhysics(struct bodies* bodylist)
{
  struct bodies new_blist = *bodylist;
  for(unsigned int i = 0; i < bodylist->size; i++)
  {
    dvec3 accel1 = calcAccelLoop(bodylist->planets[i].position, *bodylist , bodylist->planets[i].bID);
    dvec3 deltavel = multiplyDVec3ByDouble(bodylist->planets[i].velocity, TIME_STEP);
    dvec3 deltaaccel1 = multiplyDVec3ByDouble(accel1, powf(TIME_STEP, 2.0));
    dvec3 new_pos_arg1 = addDVec3ByDVec3(bodylist->planets[i].position, deltavel);
    dvec3 new_pos_arg2 = divideDVec3ByDouble(deltaaccel1, 2.0);
    dvec3 new_pos = addDVec3ByDVec3(new_pos_arg1, new_pos_arg2);

    dvec3 accel2 = calcAccelLoop(new_pos, *bodylist, bodylist->planets[i].bID);
    dvec3 accel12 = multiplyDVec3ByDouble(divideDVec3ByDouble(addDVec3ByDVec3(accel1, accel2), 2.0), TIME_STEP);
    dvec3 new_vel = addDVec3ByDVec3(bodylist->planets[i].velocity, accel12);

    new_blist.planets[i].position = new_pos;
    new_blist.planets[i].velocity = new_vel;

    /*
    for bodies in self.world.get_body_list().iter()
    {
      let accel1 = self.accel_loop(&bodies.position, &bodies.bID);
      let new_pos = bodies.position + bodies.velocity * self.time_step + ((accel1 * self.time_step.powi(2)) / 2.0f64);

      let accel2 = self.accel_loop(&new_pos, &bodies.bID);
      let new_vel = bodies.velocity + ((accel1 + accel2) / 2.0f64) * self.time_step;
    }
    */

    /*
    vec3 acceleration_1 = calcAccelLoop(bodylist.planets[i].position, bodylist, bodylist.planets[i].bID);
    vec3 new_position = multiplyVec3ByVec3(
                                      addVec3ByVec3(bodylist.planets[i].position, bodylist.planets[i].velocity),
                                      addVec3ByFloat(
                                                     divideVec3(multiplyVec3ByFloat(acceleration_1, powf(1.0f, 2.0f)), 2.0f),
                                                     1.0f
                                                     )
                                     );

    vec3 acceleration_2 = calcAccelLoop(new_position, bodylist, bodylist.planets[i].bID);
    vec3 new_velocity = multiplyVec3ByFloat(
                                           addVec3ByVec3(bodylist.planets[i].velocity, divideVec3(addVec3ByVec3(acceleration_1, acceleration_2), 2.0f)),
                                           1.0f
                                          );
    */

    /*
    vec3 acceleration_1 = calcAccelLoop(bodylist->planets[i].position, *bodylist, bodylist->planets[i].bID);
    vec3 new_position = addVec3ByVec3((bodylist->planets[i].position, multiplyVec3ByFloat(bodylist->planets[i].velocity, 1.0f)), divideVec3(multiplyVec3ByFloat(acceleration_1, powf(1.0f, 2.0f)), 2.0f));

    vec3 acceleration_2 = calcAccelLoop(new_position, *bodylist, bodylist->planets[i].bID);
    vec3 new_velocity = addVec3ByVec3(bodylist->planets[i].velocity, multiplyVec3ByFloat(divideVec3(addVec3ByVec3(acceleration_1, acceleration_2), 2.0f), 1.0f));

    bodylist->planets[i].position = new_position;
    bodylist->planets[i].velocity = new_velocity;
    */


  }

  return(new_blist);

  printf("Planets position (x, y, z) :: (%f, %f, %f) ; Planets velocity (x, y, z) :: (%f, %f, %f)\n", bodylist->planets[3].position.x, bodylist->planets[3].position.y, bodylist->planets[3].position.z,
                                                                                                      bodylist->planets[3].velocity.x, bodylist->planets[3].velocity.y, bodylist->planets[3].velocity.z);
}
