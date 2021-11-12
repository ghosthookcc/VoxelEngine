#ifndef DYN_ARRAY_H
#define DYN_ARRAY_H

#include <windows.h>

#include "vec3.h"
#include "vec4.h"

// start definition of dynFloatArray

typedef struct dynFloatArray
{
  int size;
  float* items;
} dynFloatArray;

dynFloatArray* new_dynFloatArray();

dynFloatArray* new_DynFloatArrayFromFloatArray(float fillData[], int size);

void dynFloatArray_Add(dynFloatArray** dynFloatArray, float item);

void dynFloatArray_AddVec3Values(dynFloatArray** dynFloatArray, vec3 item);

// end definition of dynFloatArray

// start definition of dynUByteArray

typedef struct dynUByteArray
{
  int size;
  unsigned char* items;
} dynUByteArray;

dynUByteArray* new_dynUByteArray();

dynUByteArray* new_DynUByteArrayFromUByteArray(unsigned char fillData[], int size);

void dynUByteArray_Add(dynUByteArray** dynUByteArray, unsigned char item);

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
void dynFuncptrArray_Add(dynFuncptrArray** dynFuncptrArray, void (*func_ptr)());

// end dynFuncptrArray

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
void dynFuncstateArray_Add(dynFuncstateArray** dynFuncstateArray, enum state state, void (*func_ptr)());

// end definition of dynFuncstateArray

// start definition of dynHandleArray

typedef struct dynHandleArray
{
  int size;
  HANDLE* handles;
} dynHandleArray;

dynHandleArray* new_dynHandleArray();
void dynHandleArray_Add(dynHandleArray** dynHandleArray, HANDLE item);

// end definition of dynHandleArray

// start definition of dynVec4Array

typedef struct dynVec4Array
{
  int size;
  int elemsSize;
  vec4* items;
} dynVec4Array;

dynVec4Array* new_dynVec4Array();
void dynVec4Array_Add(dynVec4Array** dynVec4Array, vec4 item);

// end definition of dynVec4Array

#endif
