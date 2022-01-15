#include "ComponentSystem.h"
#include <stdio.h>

void init_ComponentSystem()
{
  StartFuncs = new_dynFuncptrArray();
  UpdateFuncs = new_dynFuncptrArray();

  init_NoiseGenerator();
  init_PerlinGenerator();

  for(int Modules_iterator = 0; Modules_iterator < Modules->size; Modules_iterator++)
  {
    Load_ComponentFunc(Modules->module_ptrs[Modules_iterator]->start_proc, START);
    Load_ComponentFunc(Modules->module_ptrs[Modules_iterator]->update_proc, UPDATE);
  }
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
