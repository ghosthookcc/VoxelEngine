#ifndef COMPONENT_SYSTEM_H
#define COMPONENT_SYSTEM_H

#include <windows.h>

#include "config.h"

#include "CameraManager.h"
#include "ControlsManager.h"
#include "EntityManager.h"
#include "WorldManager.h"

#include "window.h"
#include "dynArray.h"

enum status
{
  IDLE,
  RUNNING,
  SUSPENDED,
  STOPPED,
};

//static enum state start_state;

enum status WindowStatus;

HANDLE WriteEventSignal;

dynHandleArray* ComponentsThreads;

dynFuncptrArray* StartFuncs;
dynFuncptrArray* UpdateFuncs;

void init_ComponentSystem();

void Load_ComponentFunc(void (*func_ptr)(), enum state state);

#endif
