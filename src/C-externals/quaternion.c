#include "quaternion.h"

quaternion new_Quaternion(float initX, float initY, float initZ, float initW)
{
  quaternion new_Quaternion;

  new_Quaternion.x = initX;
  new_Quaternion.y = initY;
  new_Quaternion.z = initZ;
  new_Quaternion.angle = initW;

  return new_Quaternion;
}

quaternion Identity_Quaternion()
{
  quaternion new_Quaternion;

  new_Quaternion.x = 0.0f;
  new_Quaternion.y = 0.0f;
  new_Quaternion.z = 0.0f;
  new_Quaternion.angle = 1.0f;

  return new_Quaternion;
}

void Identity_ExistingQuaternion(quaternion* quaternion)
{
  quaternion->x = 0.0f;
  quaternion->y = 0.0f;
  quaternion->z = 0.0f;
  quaternion->angle = 1.0f;
}
