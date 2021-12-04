#include "controlsManager.component.h"

vec3 getMovementVec3(mat4x4 viewMatrix, LONGLONG DeltaTime)
{
  vec3 fwd = new_vec3(viewMatrix.matrix[0][2],
                      viewMatrix.matrix[1][2],
                      viewMatrix.matrix[2][2]);
  fwd = normalizeVec3(fwd);

  vec3 newMovement = multiplyVec3ByFloat(multiplyVec3ByFloat(fwd, walkSpeed), (float)(DeltaTime));
  return(newMovement);
}

unsigned int check_RequestMove(Entity* player, mat4x4* viewMatrix, LONGLONG DeltaTime)
{
  vec3 newMovement = getMovementVec3((*viewMatrix), DeltaTime);

  if (GetAsyncKeyState(VK_SHIFT) < 0 && shiftstate.exists == 0)
  {
    walkSpeed = 0.00003f;
    shiftstate.exists = 1;
  }

  if (GetAsyncKeyState(VK_SHIFT) == 0 && shiftstate.exists == 1)
  {
    walkSpeed = 0.000003f;
    shiftstate.exists = 0;
  }

  if(GetKeyState('W') & 0x8000)
  {
    player->position.x -= newMovement.x;
    player->position.z -= newMovement.z;
    player->position.y -= newMovement.y;
    return(1);
  }

  if(GetKeyState('A') & 0x8000)
  {
    player->position.x -= newMovement.z;
    player->position.z += newMovement.x;
    return(1);
  }

  if(GetKeyState('S') & 0x8000)
  {
    player->position.x += newMovement.x;
    player->position.z += newMovement.z;
    player->position.y += newMovement.y;
    return(1);
  }

  if(GetKeyState('D') & 0x8000)
  {
    player->position.x += newMovement.z;
    player->position.z -= newMovement.x;
    return(1);
  }

  return(0);
}

unsigned int check_RequestRotate(Entity* player, mat4x4* viewMatrix, LONGLONG DeltaTime)
{
  if(GetKeyState('R') & 0x8000)
  {
    player->rotation.x = 0.0f;
    player->rotation.y = 0.0f;
    player->rotation.z = 0.0f;

    player->position.x = 0.0f;
    player->position.y = 0.0f;
    player->position.z = 2.5f;
    return(1);
  }

  // Ghosthookcc - TODO: LIMIT PITCH- AND YAW ROTATION TO BETWEEN 80-90deg. . .
  if(GetKeyState(VK_UP) & 0x8000)
  {
    player->rotation.x -= rotSpeed * DeltaTime;
    return(1);
  }

  if(GetKeyState(VK_LEFT) & 0x8000)
  {
    player->rotation.y -= rotSpeed * DeltaTime;
    return(1);
  }

  if(GetKeyState(VK_DOWN) & 0x8000)
  {
    player->rotation.x += rotSpeed * DeltaTime;
    return(1);
  }

  if(GetKeyState(VK_RIGHT) & 0x8000)
  {
    player->rotation.y += rotSpeed * DeltaTime;
    return(1);
  }

  return(0);
}
