#ifndef DYN_ARRAY_H
#define DYN_ARRAY_H

#include <windows.h>

#include "ModuleSystem.h"

#include "vec2.h"
#include "vec3.h"
#include "vec4.h"


void fillArray(void** array, void* values);

// start definition of dynFloatArray

typedef struct dynFloatArray
{
  int size;
  float* items;
} dynFloatArray;

dynFloatArray* new_dynFloatArray();

dynFloatArray* new_DynFloatArrayFromFloatArray(float fillData[], int size);

void dynFloatArray_Add(dynFloatArray** dynFloatArray, float item);

void dynFloatArray_AddBack(dynFloatArray** dynFloatArray, float item);

void dynFloatArray_AddVec3Values(dynFloatArray** dynFloatArray, vec3 item);
void dynFloatArray_AddVec2Values(dynFloatArray** dynFloatArray, vec2 item);

// end definition of dynFloatArray

// start definition of dynUIntArray

typedef struct dynUIntArray
{
  int size;
  unsigned int* items;
} dynUIntArray;

dynUIntArray* new_dynUIntArray();

dynUIntArray* new_DynUIntArrayFromUIntArray(unsigned int fillData[], int size);

void dynUIntArray_AddBack(dynUIntArray** dynUIntArray, unsigned int item);

void dynUIntArray_AddVec3Values(dynUIntArray** dynUIntArray, uivec3 item);

// end definition of dynUIntArray

// start definition of dynStringArray

typedef struct dynStringArray
{
  int size;
  char** items;
} dynStringArray;

dynStringArray* new_dynStringArray();

void dynStringArray_Add(dynStringArray** dynStringArray, char* item);

void dynStringArray_AddBack(dynStringArray** dynFloatArray, char* item);

// end definition of dynStringArray

// start definition of dynUByteArray

typedef struct dynUByteArray
{
  int size;
  unsigned char* items;
} dynUByteArray;

dynUByteArray* new_dynUByteArray();

dynUByteArray* new_DynUByteArrayFromUByteArray(unsigned char fillData[], int size);

void dynUByteArray_AddBack(dynUByteArray** dynUByteArray, unsigned char item);

void dynUByteArray_AddVec3Values(dynUByteArray** dynUByteArray, UByteVec3 item);

// end definition of dynUByteArray

// start definition of dynFuncptrArray

typedef void (*func_ptr)();
typedef struct dynFuncptrArray
{
  int size;
  func_ptr* func_ptrs;
} dynFuncptrArray;

dynFuncptrArray* new_dynFuncptrArray();
void dynFuncptrArray_AddBack(dynFuncptrArray** dynFuncptrArray, void (*func_ptr)());

// end definition dynFuncptrArray

// start definition of dynModuleArray

typedef struct dynModuleArray
{
  int size;
  GHModule** module_ptrs;
} dynModuleArray;

dynModuleArray* new_dynModuleArray();
void dynModuleArray_AddBack(dynModuleArray** dynModuleArray, GHModule* module_ptr);

// end definition dynModuleArray

// start definition of dynFuncstateArray

enum state
{
  UNKNOWN,
  START,
  UPDATE,
  RENDER,
};

typedef struct dynFuncstateArray
{
  int size;
  enum state* states;
  func_ptr* func_ptrs;
} dynFuncstateArray;

dynFuncstateArray* new_dynFuncstateArray();
void dynFuncstateArray_AddBack(dynFuncstateArray** dynFuncstateArray, enum state state, void (*func_ptr)());

// end definition of dynFuncstateArray

// start definition of dynHandleArray

typedef struct dynHandleArray
{
  int size;
  HANDLE* handles;
} dynHandleArray;

dynHandleArray* new_dynHandleArray();
void dynHandleArray_AddBack(dynHandleArray** dynHandleArray, HANDLE item);

// end definition of dynHandleArray

// start definition of dynVec4Array

typedef struct dynVec4Array
{
  int size;
  int elemsSize;
  vec4* items;
} dynVec4Array;

dynVec4Array* new_dynVec4Array();
void dynVec4Array_AddBack(dynVec4Array** dynVec4Array, vec4 item);

// end definition of dynVec4Array

#endif
