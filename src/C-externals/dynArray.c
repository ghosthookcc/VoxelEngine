#include "ghostymath.h"
#include "dynArray.h"


// start dynFloatArray

dynFloatArray* new_dynFloatArray()
{
  dynFloatArray* new_DynFloatArray = malloc(sizeof(struct dynFloatArray));
  new_DynFloatArray->items = (float*)calloc(0, sizeof(float));
  new_DynFloatArray->size = 0;
  return(new_DynFloatArray);
}

dynFloatArray* new_DynFloatArrayFromFloatArray(float fillData[], int size)
{
  dynFloatArray* new_DynFloatArray = malloc(sizeof(struct dynFloatArray) + sizeof(float) * size);
  new_DynFloatArray->size = size;
  new_DynFloatArray->items = (float*)calloc(size, sizeof(float));

  if(new_DynFloatArray->items == NULL)
  {
    free(new_DynFloatArray);
  }

  for(int i = 0; i < size; i++)
  {
    new_DynFloatArray->items[i] = fillData[i];
  }

  return(new_DynFloatArray);
}

void dynFloatArray_Add(dynFloatArray** dynFloatArray, float item)
{
  (*dynFloatArray)->size += 1;
  (*dynFloatArray) = realloc((*dynFloatArray), sizeof(struct dynFloatArray) + sizeof(float) * (*dynFloatArray)->size);
  (*dynFloatArray)->items = realloc((*dynFloatArray)->items, sizeof(float) * (*dynFloatArray)->size);
  if((*dynFloatArray)->items == NULL)
  {
    free((*dynFloatArray));
  }

  (*dynFloatArray)->items[(*dynFloatArray)->size - 1] = item;
}

void dynFloatArray_AddVec3Values(dynFloatArray** dynFloatArray, vec3 item)
{
  (*dynFloatArray)->size += 3;
  (*dynFloatArray) = realloc((*dynFloatArray), sizeof(struct dynFloatArray) + sizeof(float) * (*dynFloatArray)->size);
  (*dynFloatArray)->items = realloc((*dynFloatArray)->items, sizeof(float) * (*dynFloatArray)->size);
  if((*dynFloatArray)->items == NULL)
  {
    free((*dynFloatArray));
  }

  (*dynFloatArray)->items[(*dynFloatArray)->size - 3] = item.x;
  (*dynFloatArray)->items[(*dynFloatArray)->size - 2] = item.y;
  (*dynFloatArray)->items[(*dynFloatArray)->size - 1] = item.z;
}

// end dynFloatArray

// start dynUByteArray

dynUByteArray* new_dynUByteArray()
{
  dynUByteArray* new_DynUByteArray = malloc(sizeof(struct dynUByteArray));
  new_DynUByteArray->items = (unsigned char*)calloc(0, sizeof(unsigned char));
  new_DynUByteArray->size = 0;
  return(new_DynUByteArray);
}

dynUByteArray* new_DynUByteArrayFromUByteArray(unsigned char fillData[], int size)
{
  dynUByteArray* new_DynUByteArray = malloc(sizeof(struct dynUByteArray) + sizeof(unsigned char) * size);
  new_DynUByteArray->size = size;
  new_DynUByteArray->items = (unsigned char*)calloc(size, sizeof(unsigned char));

  if(new_DynUByteArray->items == NULL)
  {
    free(new_DynUByteArray);
  }

  for(int i = 0; i < size; i++)
  {
    new_DynUByteArray->items[i] = fillData[i];
  }

  return(new_DynUByteArray);
}

void dynUByteArray_Add(dynUByteArray** dynUByteArray, unsigned char item)
{
  (*dynUByteArray)->size += 1;
  (*dynUByteArray) = realloc((*dynUByteArray), sizeof(struct dynUByteArray) + sizeof(unsigned char) * (*dynUByteArray)->size);
  (*dynUByteArray)->items = realloc((*dynUByteArray)->items, sizeof(unsigned char) * (*dynUByteArray)->size);
  if((*dynUByteArray)->items == NULL)
  {
    free((*dynUByteArray));
  }

  (*dynUByteArray)->items[(*dynUByteArray)->size - 1] = item;
}

void dynUByteArray_AddVec3Values(dynUByteArray** dynUByteArray, UByteVec3 item)
{
  (*dynUByteArray)->size += 3;
  (*dynUByteArray) = realloc((*dynUByteArray), sizeof(struct dynUByteArray) + sizeof(unsigned char) * (*dynUByteArray)->size);
  (*dynUByteArray)->items = realloc((*dynUByteArray)->items, sizeof(unsigned int) * (*dynUByteArray)->size);
  if((*dynUByteArray)->items == NULL)
  {
    free((*dynUByteArray));
  }

  (*dynUByteArray)->items[(*dynUByteArray)->size - 3] = item.x;
  (*dynUByteArray)->items[(*dynUByteArray)->size - 2] = item.y;
  (*dynUByteArray)->items[(*dynUByteArray)->size - 1] = item.z;
}

// end dynUByteArray

// start dynFuncptrArray

dynFuncptrArray* new_dynFuncptrArray()
{
  dynFuncptrArray* new_DynFuncptrArray = malloc(sizeof(struct dynFuncptrArray));
  new_DynFuncptrArray->func_ptrs = calloc(0, 0);
  new_DynFuncptrArray->size = 0;
  return(new_DynFuncptrArray);
}

void dynFuncptrArray_Add(dynFuncptrArray** dynFuncptrArray, void (*func_ptr)())
{
  (*dynFuncptrArray)->size += 1;
  (*dynFuncptrArray) = realloc((*dynFuncptrArray), sizeof(struct dynFuncptrArray) + sizeof(func_ptr) * (*dynFuncptrArray)->size);
  (*dynFuncptrArray)->func_ptrs = realloc((*dynFuncptrArray)->func_ptrs, sizeof(func_ptr) * (*dynFuncptrArray)->size);
  if((*dynFuncptrArray)->func_ptrs == NULL)
  {
    free((*dynFuncptrArray));
  }

  (*dynFuncptrArray)->func_ptrs[(*dynFuncptrArray)->size - 1] = func_ptr;
}

// end dynFuncptrArray

// start dynFuncstateArray

dynFuncstateArray* new_dynFuncstateArray()
{
  dynFuncstateArray* new_DynFuncstateArray = malloc(sizeof(struct dynFuncstateArray));
  new_DynFuncstateArray->states = calloc(0, 0);
  new_DynFuncstateArray->func_ptrs = calloc(0, 0);
  new_DynFuncstateArray->size = 0;
  return(new_DynFuncstateArray);
}

void dynFuncstateArray_Add(dynFuncstateArray** dynFuncstateArray, enum state new_state, void (*func_ptr)())
{
  (*dynFuncstateArray)->size += 1;

  (*dynFuncstateArray) = realloc((*dynFuncstateArray), sizeof(struct dynFuncstateArray) + (sizeof(func_ptr) + sizeof(new_state)) * (*dynFuncstateArray)->size);
  (*dynFuncstateArray)->states = realloc((*dynFuncstateArray)->states, sizeof(new_state) * (*dynFuncstateArray)->size);
  (*dynFuncstateArray)->func_ptrs = realloc((*dynFuncstateArray)->func_ptrs, sizeof(func_ptr) * (*dynFuncstateArray)->size);

  if((*dynFuncstateArray)->func_ptrs == NULL)
  {
    (*dynFuncstateArray)->size -= 1;
    free((*dynFuncstateArray));
  }

  (*dynFuncstateArray)->states[(*dynFuncstateArray)->size - 1] = new_state;
  (*dynFuncstateArray)->func_ptrs[(*dynFuncstateArray)->size - 1] = func_ptr;
}

// end dynFuncstateArray

// start dynHandleArray

dynHandleArray* new_dynHandleArray()
{
  dynHandleArray* new_DynHandleArray = malloc(sizeof(struct dynHandleArray));
  new_DynHandleArray->handles = calloc(0, 0);
  new_DynHandleArray->size = 0;
  return(new_DynHandleArray);
}

void dynHandleArray_Add(dynHandleArray** dynHandleArray, HANDLE item)
{
  (*dynHandleArray)->size += 1;
  (*dynHandleArray) = realloc((*dynHandleArray), sizeof(struct dynHandleArray) + sizeof(item) * (*dynHandleArray)->size);
  (*dynHandleArray)->handles = realloc((*dynHandleArray)->handles, sizeof(item) * (*dynHandleArray)->size);
  if((*dynHandleArray)->handles == NULL)
  {
    free((*dynHandleArray));
  }

  (*dynHandleArray)->handles[(*dynHandleArray)->size - 1] = item;
}

// end dynHandleArray

// start dynVec4Array

dynVec4Array* new_dynVec4Array()
{
  dynVec4Array* new_DynVec4Array = malloc(sizeof(struct dynVec4Array));
  new_DynVec4Array->items = calloc(0, 0);
  new_DynVec4Array->elemsSize = 0;
  new_DynVec4Array->size = 0;
  return(new_DynVec4Array);
}

void dynVec4Array_Add(dynVec4Array** dynVec4Array, vec4 item)
{
  (*dynVec4Array)->elemsSize++;
  if((*dynVec4Array)->elemsSize == (*dynVec4Array)->size)
  {
    (*dynVec4Array)->size += 1;
    (*dynVec4Array) = realloc((*dynVec4Array), sizeof(struct dynVec4Array) + sizeof(item) * (*dynVec4Array)->size);
    (*dynVec4Array)->items = realloc((*dynVec4Array)->items, sizeof(item) * (*dynVec4Array)->size);

    if((*dynVec4Array)->items == NULL)
    {
      free((*dynVec4Array));
    }

    (*dynVec4Array)->items[(*dynVec4Array)->size - 1] = item;
  }
  else
  {
    (*dynVec4Array)->items[(*dynVec4Array)->size - (*dynVec4Array)->elemsSize];
  }
}

// end dynVec4Array
