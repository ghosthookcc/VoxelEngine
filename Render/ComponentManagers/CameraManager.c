#include "CameraManager.h"
#include <stdio.h>

void UpdateCamera(LONGLONG DeltaTime)
{
  if((check_RequestMove(&p_Entity, &m4_viewMatrix, DeltaTime) == 1)
  || (check_RequestRotate(&p_Entity, &m4_viewMatrix, DeltaTime) == 1))
  {
    UpdateCameraVars();
    m4_projViewMatrix = make_projViewMatrix();
    load_projViewMatrix();
  }
}
