#ifndef WINDOW_H
#define WINDOW_H
#define UNICODE

#define _CRT_SECURE_NO_WARNINGS

#include "ComponentSystem.h"
#include "ModuleSystem.h"

#include "staticRenderingVars.component.h"

#include "MasterRenderer.h"
#include "shaderClass.h"
#include "ghostymath.h"
#include "dynArray.h"
#include "vector.h"
#include "vec3.h"
#include "console.h"
#include "noise.h"
#include "perlin.h"

HGLRC hRC; // Permanent Rendering Context
HDC hDC; // Private GDI Device Context

typedef struct SetEntryPoint
{
  int (*EntryPoint)();
} SetEntryPoint;

LRESULT CALLBACK WndProc(HWND hwnd,
                         unsigned int message,
                         WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow, struct bodies *shared_mem);

void GH_InitWindow(int (*EntryPoint)());

void intialize_EntryPoint(SetEntryPoint SetEntry);

#endif
