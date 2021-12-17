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
  ambience = get_Uniformfv(programIDs->values[0], "ambient");
  if(GetKeyState('Y') & 0x8000)
  {
    ResetVec3(&player->rotation);

    player->position.x = 0.0f;
    player->position.y = 1.0f;
    player->position.z = 2.5f;

    player->scale.x = 1.0f;
    player->scale.y = 1.0f;
    player->scale.z = 1.0f;

    return(1);
  }

  if(GetKeyState(VK_F1) & 0x8000)
  {
    for(int i = 0; i < entityStack_Count(Entities); i++)
    {
      if(Entities->entities[i].scale.x < 0)
      {
        Entities->entities[i].scale.x = 0;
        continue;
      }
      Entities->entities[i].scale.x -= scaleSpeed;
    }
    return(1);
  }

  if(GetKeyState(VK_F2) & 0x8000)
  {
    for(int i = 0; i < entityStack_Count(Entities); i++)
    {
      Entities->entities[i].scale.x += scaleSpeed;
    }
    return(1);
  }

  if(GetKeyState('R') & 0x8000)
  {
    ResetVec3(&Entities->entities[SelectedEntityIndex].rotation);
    ResetVec3(&Entities->entities[SelectedEntityIndex].position);

    Entities->entities[SelectedEntityIndex].scale.x = 1.0f;
    Entities->entities[SelectedEntityIndex].scale.y = 1.0f;
    Entities->entities[SelectedEntityIndex].scale.z = 1.0f;

    return(1);
  }

  if(GetKeyState('T') & 0x8000)
  {
    for(int i = 0; i < Entities->size; i++)
    {
      ResetVec3(&Entities->entities[i].rotation);
      ResetVec3(&Entities->entities[i].position);

      Entities->entities[i].scale.x = 1.0f;
      Entities->entities[i].scale.y = 1.0f;
      Entities->entities[i].scale.z = 1.0f;

      ambience = 1.0f;
      set_Uniform1f(programIDs->values[0], "ambient", ambience);
    }
    return(1);
  }

  if(GetKeyState('E') & 0x8000)
  {
    if(SelectedEntity.vaoID != -1)
    {
      Entities->entities[SelectedEntityIndex].scale.x += scaleSpeed;
    }
    return(1);
  }

  if(GetKeyState('Q') & 0x8000)
  {
    if(SelectedEntity.vaoID != -1)
    {
      if(Entities->entities[SelectedEntityIndex].scale.x < 0)
      {
        Entities->entities[SelectedEntityIndex].scale.x = 0;
      }
      Entities->entities[SelectedEntityIndex].scale.x -= scaleSpeed;
    }
    return(1);
  }

  if(GetAsyncKeyState(VK_OEM_PLUS) == 0 && keyOEMPLUS.exists == 1) { keyOEMPLUS.exists = 0; }
  if(GetAsyncKeyState(VK_OEM_PLUS) < 0 && keyOEMPLUS.exists == 0)
  {
    keyOEMPLUS.exists = 1;
    if(ambience + 0.1f <= 2.0f)
      ambience += 0.1f;
    else
      ambience = 3.0f;

    set_Uniform1f(programIDs->values[0], "ambient", ambience);
    return(1);
  }

  if(GetAsyncKeyState(VK_OEM_MINUS) == 0 && keyOEMMINUS.exists == 1) { keyOEMMINUS.exists = 0; }
  if(GetAsyncKeyState(VK_OEM_MINUS) < 0 && keyOEMMINUS.exists == 0)
  {
    keyOEMMINUS.exists = 1;
    if(ambience - 0.1f >= 0.6f)
      ambience -= 0.1f;
    else
      ambience = 0.6f;

    set_Uniform1f(programIDs->values[0], "ambient", ambience);
    return(1);
  }

  if(GetAsyncKeyState(0x32) == 0 && key2Down.exists == 1) { key2Down.exists = 0; }
  if(GetAsyncKeyState(0x32) < 0 && key2Down.exists == 0 && Entities->size > 0)
  {
    key2Down.exists = 1;
    int index = entityStack_GetIndex(Entities, SelectedEntity);
    if(SelectedEntity.vaoID != -1)
    {
      if(index + 1 < Entities->size)
      {
        SelectedEntity = Entities->entities[index + 1];
        SelectedEntityIndex = index + 1;
      } else { return(0); }
    }
    else
    {
      if(Entities->size == 0) { return(0); }

      SelectedEntity = entityStack_Peek(Entities);
    }
    return(1);
  }

  if(GetAsyncKeyState(0x31) == 0 && key1Down.exists == 1) { key1Down.exists = 0; }
  if(GetAsyncKeyState(0x31) < 0 && key1Down.exists == 0)
  {
    key1Down.exists = 1;
    int index = entityStack_GetIndex(Entities, SelectedEntity);
    if(SelectedEntity.vaoID != -1)
    {
      if(index - 1 >= 0)
      {
        SelectedEntity = Entities->entities[index - 1];
        SelectedEntityIndex = index - 1;
      } else { return(0); }
    }
    else
    {
      if(Entities->size == 0) { return(0); }

      SelectedEntity = entityStack_Peek(Entities);
    }
    return(1);
  }

  return(0);
}
