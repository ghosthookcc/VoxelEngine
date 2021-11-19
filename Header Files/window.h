#ifndef WINDOW_H
#define WINDOW_H
#define UNICODE

#include <stdio.h>

#include "ComponentSystem.h"
#include "ModuleSystem.h"

#include "staticRenderingVars.component.h"

#include "commonIncludes.inc.h"
#include "MasterRenderer.h"
#include "shaderClass.h"
#include "ghostymath.h"
#include "dynArray.h"
#include "vec3.h"

HGLRC hRC; // Permanent Rendering Context
HDC hDC; // Private GDI Device Context

LRESULT CALLBACK WndProc(HWND hwnd,
                         unsigned int message,
                         WPARAM wParam, LPARAM lParam);

int WINAPI WinMain();

void GH_InitWindow(void (*EntryPoint)());

#endif
