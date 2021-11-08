#ifndef QUATERNION_H
#define QUATERNION_H

#include "vec4.h"

typedef struct
{
  float x;
  float y;
  float z;
  float angle;
} quaternion;

quaternion new_Quaternion(float initX, float initY, float initZ, float initW);
quaternion Identity_Quaternion();

void Identity_ExistingQuaternion(quaternion* quaternion);

#endif
