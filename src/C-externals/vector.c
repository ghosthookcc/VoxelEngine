#include "vector.h"

// define enums needed for functions
// define static vars & constant vars
static const int int_emptySpaceVal   = 21222399;
static const unsigned int uint_emptySpaceVal = 2323232;
static const float float_emptySpaceVal = 0.7799001f;

// start intVectorCached functions

intVectorCached* new_intVectorCached(int size)
{
  intVectorCached* construct = malloc(sizeof(struct intVectorCached) + sizeof(int) * size);

  construct->values = (int*)calloc(size, sizeof(int*));
  construct->size = size;
  construct->lastEmplaceBackIndex = 0;
  construct->lastPushIndex = 0;

  for(int i = 0; i < construct->size; i++)
  {
    construct->values[i] = int_emptySpaceVal;
  }

  return construct;
}

// Nicolas Cage
void intVectorCached_EmplaceBack(intVectorCached** vector, int item)
{
  /*
  int i = 0;
  if((*vector)->lastEmplaceBackIndex > 0)
  {
    if((*vector)->lastEmplaceBackIndex - (*vector)->lastPushIndex < (*vector)->lastPushIndex - (*vector)->lastEmplaceBackIndex)
    {
      (i = (*vector)->lastEmplaceBackIndex - (*vector)->lastPushIndex);
    } else { (i = (*vector)->lastPushIndex - (*vector)->lastEmplaceBackIndex); }
  }
  */
  int i = (*vector)->lastEmplaceBackIndex;

  for(i; i > -1; i--)
  {
    if ((*vector)->values[i] == int_emptySpaceVal)
    {
        intVectorCached_Rotate((*vector), 1, LEFT);
        (*vector)->values[(*vector)->size-1] = item;
        (*vector)->lastEmplaceBackIndex = i;
        break;
    }
    else if (i == 0 && (*vector)->values[0] != int_emptySpaceVal)
    {
      (*vector)->size += 1;

      intVectorCached* tmpVec = realloc((*vector), intVectorCached_GetStackAllocSize(vector));
      int* tmpVecValues = realloc((*vector)->values, intVectorCached_GetItemsAllocSize(vector));

      if(tmpVec == NULL || tmpVecValues == NULL)
      {
        printf("%s", "-=PUSH INTVEC - OUT OF MEMORY=-");
      }

      (*vector) = tmpVec;
      (*vector)->values = tmpVecValues;

      (*vector)->values[(*vector)->size-1] = item;
      (*vector)->lastEmplaceBackIndex = i;
      break;
    }
  }
}

void intVectorCached_Push(intVectorCached** vector, int item)
{
  /*
  int i = 0;
  if((*vector)->lastPushIndex > 0)
  {
    if((*vector)->lastPushIndex - (*vector)->lastEmplaceBackIndex < (*vector)->lastEmplaceBackIndex - (*vector)->lastPushIndex)
    {
      (i = (*vector)->lastPushIndex - (*vector)->lastEmplaceBackIndex);
    } else { (i = (*vector)->lastEmplaceBackIndex - (*vector)->lastPushIndex); }
  }
  */

  int i = (*vector)->lastPushIndex;
  for(i; i < (*vector)->size; i++)
  {
    if ((*vector)->values[i] == int_emptySpaceVal)
    {
      intVectorCached_Rotate((*vector), 1, RIGHT);
      (*vector)->values[0] = item;
      (*vector)->lastPushIndex = i;
      break;
    }
    else if (i == (*vector)->size-1 && (*vector)->values[(*vector)->size-1] != int_emptySpaceVal)
    {
      (*vector)->size += 1;

      intVectorCached* tmpVec = realloc((*vector), intVectorCached_GetStackAllocSize(vector));
      int* tmpVecValues = realloc((*vector)->values, intVectorCached_GetItemsAllocSize(vector));

      if(tmpVec == NULL || tmpVecValues == NULL)
      {
        printf("%s", "-=PUSH UINTVEC - OUT OF MEMORY=-");
      }

      (*vector) = tmpVec;
      (*vector)->values = tmpVecValues;

      intVectorCached_Rotate((*vector), 1, RIGHT);
      (*vector)->values[0] = item;
      (*vector)->lastPushIndex = i;
      break;
    }
  }
}

void unsafe_intVectorCached_Insert(intVectorCached** vector, int index, int item)
{
  ((*vector)->values[index] = item);
}

void intVectorCached_Rotate(intVectorCached* vector, int rotateN, enum direction direction)
{
  int i;
  int posNum;

  if(direction == RIGHT)
  {
    for(int x = 0; x < rotateN; x++)
    {
      posNum = vector->values[vector->size-1];;

      for(i = vector->size-1; i > 0; i--)
      {
        vector->values[i] = vector->values[i-1];
      }

      vector->values[0] = posNum;
    }
  }
  else if(direction == LEFT)
  {
    for(int x = 0; x < rotateN; x++)
    {
      posNum = vector->values[0];

      for(i = 0; i < vector->size; i++)
      {
        vector->values[i] = vector->values[i+1];
      }

      vector->values[i] = posNum;
    }
  }
}

int intVectorCached_Count(intVectorCached* vector)
{
  return(vector->size);
}

int intVectorCached_GetStackAllocSize(intVectorCached** vector)
{
  return(sizeof(struct intVectorCached) + (*vector)->size * sizeof(int));
}

int intVectorCached_GetItemsAllocSize(intVectorCached** vector)
{
  return((*vector)->size * sizeof(int));
}

// end intVectorCached functions

// start intVector functions

intVector* new_intVector(int size)
{
  intVector* construct = malloc(sizeof(struct intVector) + sizeof(int) * size);

  construct->values = (int*)calloc(size, sizeof(int*));
  construct->size = size;

  for(int i = 0; i < construct->size; i++)
  {
      construct->values[i] = int_emptySpaceVal;
  }

  return construct;
}

// Nicolas Cage
void intVector_EmplaceBack(intVector** vector, int item)
{
  for(int i = (*vector)->size-1; i > -1; i--)
  {
    if ((*vector)->values[i] == int_emptySpaceVal)
    {
        intVector_Rotate((*vector), 1, LEFT);
        (*vector)->values[(*vector)->size-1] = item;
        break;
    }
    else if (i == 0 && (*vector)->values[0] != int_emptySpaceVal)
    {
      (*vector)->size += 1;

      intVector* tmpVec = realloc((*vector), intVector_GetStackAllocSize(vector));
      int* tmpVecValues = realloc((*vector)->values, intVector_GetItemsAllocSize(vector));

      if(tmpVec == NULL || tmpVecValues == NULL)
      {
        printf("%s", "-=PUSH INTVEC - OUT OF MEMORY=-");
      }

      (*vector) = tmpVec;
      (*vector)->values = tmpVecValues;

      (*vector)->values[(*vector)->size-1] = item;
      break;
    }
  }
}

void intVector_Push(intVector** vector, int item)
{
  for(int i = 0; i < (*vector)->size; i++)
  {
    if ((*vector)->values[i] == int_emptySpaceVal)
    {
      intVector_Rotate((*vector), 1, RIGHT);
      (*vector)->values[0] = item;
      break;
    }
    else if (i == (*vector)->size-1 && (*vector)->values[(*vector)->size-1] != int_emptySpaceVal)
    {
      (*vector)->size += 1;

      intVector* tmpVec = realloc((*vector), intVector_GetStackAllocSize(vector));
      int* tmpVecValues = realloc((*vector)->values, intVector_GetItemsAllocSize(vector));

      if(tmpVec == NULL || tmpVecValues == NULL)
      {
        printf("%s", "-=PUSH UINTVEC - OUT OF MEMORY=-");
      }

      (*vector) = tmpVec;
      (*vector)->values = tmpVecValues;

      intVector_Rotate((*vector), 1, RIGHT);
      (*vector)->values[0] = item;
      break;
    }
  }
}

void unsafe_intVector_Insert(intVector** vector, int index, int item)
{
  ((*vector)->values[index] = item);
}

void intVector_Rotate(intVector* vector, int rotateN, enum direction direction)
{
  int i;
  int posNum;

  if(direction == RIGHT)
  {
    for(int x = 0; x < rotateN; x++)
    {
      posNum = vector->values[vector->size-1];;

      for(i = vector->size-1; i > 0; i--)
      {
        vector->values[i] = vector->values[i-1];
      }

      vector->values[0] = posNum;
    }
  }
  else if(direction == LEFT)
  {
    for(int x = 0; x < rotateN; x++)
    {
      posNum = vector->values[0];

      for(i = 0; i < vector->size; i++)
      {
        vector->values[i] = vector->values[i+1];
      }

      vector->values[i] = posNum;
    }
  }
}

int intVector_Count(intVector* vector)
{
  return(vector->size);
}

int intVector_GetStackAllocSize(intVector** vector)
{
  return(sizeof(struct intVector) + (*vector)->size * sizeof(int));
}

int intVector_GetItemsAllocSize(intVector** vector)
{
  return((*vector)->size * sizeof(int));
}

// end intVector functions

// start unsigned intVector functions

uintVector* new_uintVector(int size)
{
  uintVector* construct = malloc(sizeof(struct uintVector) + sizeof(unsigned int) * size);

  construct->values = (unsigned int*)calloc(size, sizeof(unsigned int*));
  construct->size = size;

  for(int i = 0; i < construct->size; i++)
  {
      construct->values[i] = uint_emptySpaceVal;
  }

  return construct;
}

// Nicolas Cage
void uintVector_EmplaceBack(uintVector** vector, unsigned int item)
{
  for(int i = (*vector)->size-1; i > -1; i--)
  {
    if ((*vector)->values[i] == uint_emptySpaceVal)
    {
      uintVector_Rotate((*vector), 1, LEFT);
      (*vector)->values[(*vector)->size-1] = item;
      break;
    }
    else if (i == 0 && (*vector)->values[0] != uint_emptySpaceVal)
    {
      (*vector)->size += 1;

      uintVector* tmpVec = realloc((*vector), uintVector_GetStackAllocSize(vector));
      unsigned int* tmpVecValues = realloc((*vector)->values, uintVector_GetItemsAllocSize(vector));

      if(tmpVec == NULL || tmpVecValues == NULL)
      {
        printf("%s", "-=PUSH UINTVEC - OUT OF MEMORY=-");
      }

      (*vector) = tmpVec;
      (*vector)->values = tmpVecValues;

      (*vector)->values[(*vector)->size-1] = item;
      break;
    }
  }
}

void uintVector_Push(uintVector** vector, unsigned int item)
{
  for(int i = 0; i < (*vector)->size; i++)
  {
    if ((*vector)->values[i] == uint_emptySpaceVal)
    {
      uintVector_Rotate((*vector), 1, RIGHT);
      (*vector)->values[0] = item;
      break;
    }
    else if (i == (*vector)->size-1 && (*vector)->values[(*vector)->size-1] != uint_emptySpaceVal)
    {
      (*vector)->size += 1;

      uintVector* tmpVec = realloc((*vector), uintVector_GetStackAllocSize(vector));
      unsigned int* tmpVecValues = realloc((*vector)->values, uintVector_GetItemsAllocSize(vector));

      if(tmpVec == NULL || tmpVecValues == NULL)
      {
        printf("%s", "-=PUSH UINTVEC - OUT OF MEMORY=-");
      }

      (*vector) = tmpVec;
      (*vector)->values = tmpVecValues;

      uintVector_Rotate((*vector), 1, RIGHT);
      (*vector)->values[0] = item;
      break;
    }
  }
}

void unsafe_uintVector_Insert(uintVector** vector, int index, unsigned int item)
{
  ((*vector)->values[index] = item);
}

void uintVector_Rotate(uintVector* vector, int rotateN, enum direction direction)
{
  int i;
  unsigned int posNum;

  if(direction == RIGHT)
  {
    for(int x = 0; x < rotateN; x++)
    {
      posNum = vector->values[vector->size-1];;

      for(i = vector->size-1; i > 0; i--)
      {
        vector->values[i] = vector->values[i-1];
      }

      vector->values[0] = posNum;
    }
  }
  else if(direction == LEFT)
  {
    for(int x = 0; x < rotateN; x++)
    {
      posNum = vector->values[0];

      for(i = 0; i < vector->size; i++)
      {
        vector->values[i] = vector->values[i+1];
      }

      vector->values[i] = posNum;
    }
  }
}

int uintVector_Count(uintVector* vector)
{
  return(vector->size);
}

int uintVector_GetStackAllocSize(uintVector** vector)
{
  return(sizeof(struct uintVector) + (*vector)->size * sizeof(unsigned int));
}

int uintVector_GetItemsAllocSize(uintVector** vector)
{
  return((*vector)->size * sizeof(unsigned int));
}

// end unsigned intVector functions

// start floatVector functions

floatVector* new_floatVector(int size)
{
  floatVector* construct = malloc(sizeof(struct floatVector) + sizeof(float) * size);

  construct->values = (float*)calloc(size, sizeof(float*));
  construct->size = size;

  for(int i = 0; i < construct->size; i++)
  {
      construct->values[i] = float_emptySpaceVal;
  }

  return construct;
}

// Nicolas Cage
void floatVector_EmplaceBack(floatVector** vector, float item)
{
  for(int i = (*vector)->size-1; i > -1; i--)
  {
    if ((*vector)->values[i] == float_emptySpaceVal)
    {
      floatVector_Rotate((*vector), 1, LEFT);
      (*vector)->values[(*vector)->size-1] = item;
      break;
    }
    else if (i == 0 && (*vector)->values[0] != float_emptySpaceVal)
    {
      (*vector)->size += 1;

      floatVector* tmpVec = realloc((*vector), floatVector_GetStackAllocSize(vector));
      float* tmpVecValues = realloc((*vector)->values, floatVector_GetItemsAllocSize(vector));

      if(tmpVec == NULL || tmpVecValues == NULL)
      {
        printf("%s", "-=PUSH FLOATVEC - OUT OF MEMORY=-");
      }

      (*vector) = tmpVec;
      (*vector)->values = tmpVecValues;

      (*vector)->values[(*vector)->size-1] = item;
      break;
    }
  }
}

void floatVector_Push(floatVector** vector, float item)
{
  for(int i = 0; i < (*vector)->size; i++)
  {
    if (i == (*vector)->size-1 && (*vector)->values[(*vector)->size-1] != float_emptySpaceVal)
    {
      (*vector)->size += 1;

      floatVector* tmpVec = realloc((*vector), floatVector_GetStackAllocSize(vector));
      float* tmpVecValues = realloc((*vector)->values, floatVector_GetItemsAllocSize(vector));

      if(tmpVec == NULL || tmpVecValues == NULL)
      {
        printf("%s", "-=PUSH FLOATVEC - OUT OF MEMORY=-");
      }

      (*vector) = tmpVec;
      (*vector)->values = tmpVecValues;

      floatVector_Rotate((*vector), 1, RIGHT);
      (*vector)->values[0] = item;
      break;
    }
    else if ((*vector)->values[i] == float_emptySpaceVal)
    {
      floatVector_Rotate((*vector), 1, RIGHT);
      (*vector)->values[0] = item;
      break;
    }
  }
}

void unsafe_floatVector_Insert(floatVector** vector, int index, float item)
{
  ((*vector)->values[index] = item);
}

void floatVector_Rotate(floatVector* vector, int rotateN, enum direction direction)
{
  int i;
  float posNum;

  if(direction == RIGHT)
  {
    for(int x = 0; x < rotateN; x++)
    {
      posNum = vector->values[vector->size-1];;

      for(i = vector->size-1; i > 0; i--)
      {
        vector->values[i] = vector->values[i-1];
      }

      vector->values[0] = posNum;
    }
  }
  else if(direction == LEFT)
  {
    for(int x = 0; x < rotateN; x++)
    {
      posNum = vector->values[0];

      for(i = 0; i < vector->size; i++)
      {
        vector->values[i] = vector->values[i+1];
      }

      vector->values[i] = posNum;
    }
  }
}

int floatVector_Count(floatVector* vector)
{
  return(vector->size);
}

int floatVector_GetStackAllocSize(floatVector** vector)
{
  return(sizeof(struct floatVector) + (*vector)->size * sizeof(float));
}

int floatVector_GetItemsAllocSize(floatVector** vector)
{
  return((*vector)->size * sizeof(float));
}

// end floatVector funtions
