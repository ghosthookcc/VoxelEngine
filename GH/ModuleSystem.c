#include "ModuleSystem.h"

#include <stdio.h>

void init_ModuleSystem()
{
  SetDllDirectoryW(L"../Dependencies/dlls");
  Modules = new_dynModuleArray();

  dynModuleArray_AddBack(&Modules, Load_GHModule("../../Debug/modules.dll"));
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
    else
    {
      wchar_t warningBuffer[256];
      FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
               NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
               warningBuffer, (sizeof(warningBuffer) / sizeof(wchar_t)), NULL);
      MessageBoxW(0,
                 warningBuffer,
                 L"-=WARNING=-",
                 MB_OK | MB_ICONWARNING);
    }

    return(newmod);
}

int Free_GHModule(GHModule* module)
{
    FreeLibrary(module->hDLL);
    free(module);
    return 0;
}
