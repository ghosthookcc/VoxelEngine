#ifndef MODULE_SYSTEM_H
#define MODULE_SYSTEM_H

#include <windows.h>

#include "exportlogic.h"

#define ModuleExport MODULES_EXPORT

typedef void (__cdecl* MODULEPROC)();
typedef struct GHModule
{
  HINSTANCE hDLL;
  MODULEPROC name_var;
  MODULEPROC start_proc;
  MODULEPROC update_proc;
} GHModule;

void init_ModuleSystem();

GHModule* Load_GHModule(LPCSTR path);

int Free_GHModule(GHModule* module);         

#endif                                                                                                                                                                                                                                                                                        
