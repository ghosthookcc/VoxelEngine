#include "controlsManager.component.h"
#include <stdio.h>

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
    scaleSpeed = 0.01f;
    shiftstate.exists = 1;
  }

  if (GetAsyncKeyState(VK_SHIFT) == 0 && shiftstate.exists == 1)
  {
    walkSpeed = 0.000003f;
    scaleSpeed = 0.001f;
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

  if(GetKeyState('Q') & 0x8000)
  {
    for(int i = 0; i < entityStack_Count(Entities); i++)
    {
      if(Entities->entities[i].scale.x <= 0)
      {
        Entities->entities[i].scale.x = 0;
        continue;
      }
      Entities->entities[i].scale.x -= scaleSpeed;
    }
  }

  if(GetKeyState('E') & 0x8000)
  {
    for(int i = 0; i < entityStack_Count(Entities); i++)
    {
      Entities->entities[i].scale.x += scaleSpeed;
    }
  }

  return(0);
}

unsigned int check_RequestRotate(Entity* player, mat4x4* viewMatrix, LONGLONG DeltaTime)
{
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

unsigned int check_RequestCommand(Entity* player, mat4x4* viewMatrix, LONGLONG DeltaTime)
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

  if(GetKeyState('Q') & 0x8000)
  {
    return(1);
  }

  if(GetAsyncKeyState(0x32) == 0 && key2Down.exists == 1) { key2Down.exists = 0; }
  if(GetAsyncKeyState(0x32) < 0 && key2Down.exists == 0 && Entities->size > 0)
  {
    key2Down.exists = 1;
    int index = entityStack_GetIndex(Entities, SelectedEntity);
    if(index >= 0 && index < Entities->size)
    {
      if(SelectedEntity.vaoID != -1)
      {
        printf("\n\nindex :: %i ;\n\n", index);
        printf("\n\nindex + 1 = %i ;\n\n", index - 1);
        if(index - 1 < Entities->size)
        {
          SelectedEntity = Entities->entities[index - 1];
        } else { printf("\n\nerrorkey2-1\n\n"); return(0); }
      }
      else
      {
        if(Entities->size == 0) { printf("\n\nerrorkey2-2\n\n"); return(0); }

        SelectedEntity = entityStack_Peek(Entities);
      }
      printf("\n\nSelectedEntityVAOID :: %i ;\n\n", SelectedEntity.vaoID);
      return(1);
    }
  }

  if(GetAsyncKeyState(0x31) == 0 && key1Down.exists == 1) { key1Down.exists = 0; }
  if(GetAsyncKeyState(0x31) < 0 && key1Down.exists == 0)
  {
    key1Down.exists = 1;
    int index = entityStack_GetIndex(Entities, SelectedEntity);
    if(index >= 0 && index < Entities->size)
    {
      if(SelectedEntity.vaoID != -1)
      {
        printf("\n\nindex :: %i ;\n\n", index);
        printf("\n\nindex - 1 = %i ;\n\n", index + 1);
        if(index + 1 >= 0)
        {
          SelectedEntity = Entities->entities[index + 1];
        } else { printf("\n\nerrorkey1-1\n\n"); return(0); }
      }
      else
      {
        if(Entities->size == 0) { printf("\n\nerrorkey1-2\n\n"); return(0); }

        SelectedEntity = entityStack_Peek(Entities);
      }
      printf("\n\nSelectedEntityVAOID :: %i ;\n\n", SelectedEntity.vaoID);
      return(1);
    }
  }

  return(0);
}
