#ifndef START_MENU_H
#define START_MENU_H

#include <windows.h>

#include "generics.h"

static HANDLE hStdOut = NULL;

HWND WindowHandle;

const static char* StringConstructorOptionValues[3];

enum StringConstructorOption
{
  NEWLINE = 0,
  DOUBLENEWLINE = 1,
  SPACING = 2,
  NONE = 3
};

typedef struct StringConstructor
{
  char* StringBuild;
} StringConstructor;

void init_ConsoleSystem();

StringConstructor* init_StringConstructor();
void addToStringConstructor(StringConstructor** constructor, const char* str, enum StringConstructorOption option);

void AcquireStdOutHandle();

HANDLE GET_hStdOut();
void Write_CommandLineHelpMenu();

DWORD WriteToConsole(const char* buffer);

#endif
