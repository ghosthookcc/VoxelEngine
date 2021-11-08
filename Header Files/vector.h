#ifndef VECTOR_H
#define VECTOR_H

#include <malloc.h>

#include "ghostymath.h"

// start enum definitions

enum direction
{
  LEFT,
  RIGHT
};

enum vectorAction
{
  EMPLACEBACK,
  PUSH
};

// end enum definitions

// start definition of intVectorCached

typedef struct intVectorCached
{
  int* values;
  int size;
  int lastEmplaceBackIndex;
  int lastPushIndex;
} intVectorCached;

intVectorCached* new_intVectorCached(int size);

void intVectorCached_EmplaceBack(intVectorCached** vector, int item);
void intVectorCached_Push(intVectorCached** vector, int item);

void unsafe_intVectorCached_Insert(intVectorCached** vector, int index, int item);

void intVectorCached_Rotate(intVectorCached* vector, int rotateN, enum direction direction);
int intVectorCached_Count(intVectorCached* vector);

int intVectorCached_GetStackAllocSize(intVectorCached** vector);
int intVectorCached_GetItemsAllocSize(intVectorCached** vector);

// end definition of intVectorCached

// start definitions of intVector

typedef struct intVector
{
  int* values;
  int size;
} intVector;

intVector* new_intVector(int size);

void intVector_EmplaceBack(intVector** vector, int item);
void intVector_Push(intVector** vector, int item);

void unsafe_intVector_Insert(intVector** vector, int index, int item);

void intVector_Rotate(intVector* vector, int rotateN, enum direction direction);
int intVector_Count(intVector* vector);

int intVector_GetStackAllocSize(intVector** vector);
int intVector_GetItemsAllocSize(intVector** vector);

// end definitions of intVector

// start definitions of unsigned intVector

typedef struct uintVector
{
  unsigned int* values;
  int size;
} uintVector;

uintVector* new_uintVector(int size);

void uintVector_EmplaceBack(uintVector** vector, unsigned int item);
void uintVector_Push(uintVector** vector, unsigned int item);

void unsafe_uintVector_Insert(uintVector** vector, int index, unsigned int item);

void uintVector_Rotate(uintVector* vector, int rotateN, enum direction direction);
int uintVector_Count(uintVector* vector);

int uintVector_GetStackAllocSize(uintVector** vector);
int uintVector_GetItemsAllocSize(uintVector** vector);

// end definitions of unsigned intVector

// start definitions of floatVector

typedef struct floatVector
{
  float* values;
  int size;
} floatVector;

floatVector* new_floatVector(int size);

void floatVector_EmplaceBack(floatVector** vector, float item);
void floatVector_Push(floatVector** vector, float item);

void unsafe_floatVector_Insert(floatVector** vector, int index, float item);

void floatVector_Rotate(floatVector* vector, int rotateN, enum direction direction);
int floatVector_Count(floatVector* vector);

int floatVector_GetStackAllocSize(floatVector** vector);
int floatVector_GetItemsAllocSize(floatVector** vector);

// end definitions of floatVector

#endif
