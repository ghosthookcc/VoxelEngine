#include "ComponentSystem.h"

void init_ComponentSystem()
{
  StartFuncs = new_dynFuncptrArray();
  UpdateFuncs = new_dynFuncptrArray();
}

void Load_ComponentFunc(void (*func_ptr)(), enum state state)
{
  switch(state)
  {
    case START:
      dynFuncptrArray_AddBack(&StartFuncs, func_ptr);
      break;
    case UPDATE:
      dynFuncptrArray_AddBack(&UpdateFuncs, func_ptr);
      break;
  }
}
