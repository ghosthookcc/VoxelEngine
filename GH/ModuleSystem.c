#include "ModuleSystem.h"

#include <stdio.h>

void init_ModuleSystem()
{
  SetDllDirectoryW(L"Dependencies/dlls");
}

GHModule* Load_GHModule(LPCSTR path)
{
    HMODULE hDLL = LoadLibraryA(TEXT(path));
    GHModule* newmod = malloc(sizeof(newmod));

    if(hDLL != NULL)
    {
      newmod->hDLL = hDLL;
      newmod->name_var = (MODULEPROC)GetProcAddress(hDLL, "var_name");
      newmod->start_proc = (MODULEPROC)GetProcAddress(hDLL, "start");
      newmod->update_proc = (MODULEPROC)GetProcAddress(hDLL, "update");
    }

    return(newmod);
}

int Free_GHModule(GHModule* module)
{
    FreeLibrary(module->hDLL);
    free(module);
    return 0;
}
