#ifndef CONTROLS_MANAGER_COMPONENT_H
#define CONTROLS_MANAGER_COMPONENT_H

#include "ghostymath.h"

#include "staticChunkManager.component.h"

#include "entityManager.component.h"

static float walkSpeed = 0.000003f;
static float scaleSpeed =  0.001f;
static TOF_Flag shiftstate = { 0 };
static float rotSpeed = 0.005f;

vec3 p_Acceleration;

vec3 getMovementVec3(mat4x4 viewMatrix, LONGLONG DeltaTime);

unsigned int check_RequestMove(Entity* player, mat4x4* viewMatrix, LONGLONG DeltaTime);
unsigned int check_RequestRotate(Entity* player, mat4x4* viewMatrix, LONGLONG DeltaTime);

#endif
