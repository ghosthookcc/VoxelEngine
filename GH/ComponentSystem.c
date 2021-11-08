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
      dynFuncptrArray_Add(&StartFuncs, func_ptr);
      break;
    case UPDATE:
      dynFuncptrArray_Add(&UpdateFuncs, func_ptr);
      break;
  }
}
