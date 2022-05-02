#ifndef COMPONENT_SYSTEM_H
#define COMPONENT_SYSTEM_H

#include <windows.h>

#include "ModuleSystem.h"

#include "staticRenderingVars.component.h"
#include "staticVoxelGeometry.component.h"

#include "cameraManager.component.h"
#include "controlsManager.component.h"
#include "entityManager.component.h"
#include "mesh.component.h"
#include "worldManager.component.h"

#include "window.h"
#include "generics.h"
#include "vec3.h"
#include "dynArray.h"
#include "console.h"
#include "perlin.h"

enum status
{
  IDLE,
  RUNNING,
  SUSPENDED,
  STOPPED,
};

enum status WindowStatus;

HANDLE WriteEventSignal;

dynHandleArray* ComponentsThreads;

dynFuncptrArray* StartFuncs;
dynFuncptrArray* UpdateFuncs;

void init_ComponentSystem();

void Load_ComponentFunc(void (*func_ptr)(), enum state state);

#endif
