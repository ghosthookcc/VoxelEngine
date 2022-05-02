#include "generics.h"

// start definition standard funcs

char* concat_string(const char* str1, const char* str2)
{
    const int len1 = (const int)get_cstrlen(str1);
    const int len2 = (const int)get_cstrlen(str2);

    char* result = malloc(len1 + len2 + 1);
    if(!result) return result;
    CopyMemory(result, str1, len1);
    CopyMemory(result + len1, str2, len2 + 1);
    return(result);
}

size_t get_strlen(char* ptr)
{
    int len = 0;
    while(*ptr)
    {
        len++;
        *ptr++;
    }
    return(len);
}

size_t get_cstrlen(const char* ptr)
{
    int len = 0;
    while(*ptr)
    {
        len++;
        *ptr++;
    }
    return(len);
}

// end definition standard funcs

// start uIntStack funcs

uIntStack* init_UIntStack()
{
  uIntStack* stack = malloc(sizeof(struct uIntStack));

  stack->StackItems = (unsigned int*)calloc(0, sizeof(unsigned int*));
  stack->top = 0;
  stack->size = 0;

  return(stack);
}

uIntStack* uIntStack_Push(uIntStack* stack, unsigned int item)
{
  stack->size += 1;

  uIntStack* tmpStack = realloc(stack, uIntStack_GetStackAllocSize(stack));
  unsigned int* tmpStackValues = realloc(stack->StackItems, uIntStack_GetItemsAllocSize(stack));

  stack = tmpStack;
  stack->StackItems = tmpStackValues;

  uIntStack_Rotate(stack, 1);
  stack->StackItems[0] = item;
  stack->top = &stack->StackItems[0];

  return(stack);
}

uIntStack* uIntStack_Pop(uIntStack* stack)
{
  if(uIntStack_Count(stack) > 0)
  {
    stack->size -= 1;

    for(int i = 0; i < stack->size-1; i++)
    {
      stack->StackItems[i] = stack->StackItems[i + 1];
    }

    uIntStack* tmpStack = realloc(stack, uIntStack_GetStackAllocSize(stack));
    unsigned int* tmpStackValues = realloc(stack->StackItems, uIntStack_GetItemsAllocSize(stack));

    stack = tmpStack;
    stack->StackItems = tmpStackValues;

    if(uIntStack_Count(stack) > 0)
      stack->top = &stack->StackItems[0];
  }

  return(stack);
}

unsigned int uIntStack_Peek(uIntStack* stack)
{
  return(*(stack->top));
}

void uIntStack_Rotate(uIntStack* stack, int rotateN)
{
  int i;
  unsigned int posNum;

  for(int x = 0; x < rotateN; x++)
  {
    posNum = stack->StackItems[uIntStack_Count(stack) - 1];;

    for(i = uIntStack_Count(stack) - 1; i > 0; i--)
    {
      stack->StackItems[i] = stack->StackItems[i-1];
    }

    stack->StackItems[0] = posNum;
  }
}

int uIntStack_Count(uIntStack* stack)
{
  return(stack->size);
}

int uIntStack_GetStackAllocSize(uIntStack* stack)
{
  return(sizeof(struct uIntStack) + stack->size * sizeof(unsigned int*));
}

int uIntStack_GetItemsAllocSize(uIntStack* stack)
{
  return(stack->size * sizeof(unsigned int*));
}

// end uIntStack funcs

// start EntityStack initGLFuncs

EntityStack* init_EntityStack()
{
  EntityStack* stack = malloc(sizeof(struct EntityStack));

  stack->entities = (Entity*)calloc(0, sizeof(Entity*));
  stack->top;
  stack->size = 0;

  return(stack);
}

void entityStack_Push(EntityStack** stack, Entity* entity)
{
  (*stack)->size += 1;

  EntityStack* tmpStack = realloc((*stack), entityStack_GetStackAllocSize(stack));
  Entity* tmpStackValues = realloc((*stack)->entities, entityStack_GetItemsAllocSize(stack));

  if(tmpStack == NULL || tmpStackValues == NULL)
  {
    printf("%s", "-=PUSH - OUT OF MEMORY=-");
  }

  (*stack) = tmpStack;
  (*stack)->entities = tmpStackValues;

  entityStack_Rotate((*stack), 1);
  (*stack)->entities[0] = *(entity);
  (*stack)->top = (*stack)->entities[0];
}

void entityStack_Pop(EntityStack** stack)
{
  if(entityStack_Count((*stack)) > 0)
  {
    (*stack)->size -= 1;

    for(int i = 0; i < entityStack_Count((*stack)); i++)
    {
      (*stack)->entities[i] = (*stack)->entities[i + 1];
    }

    EntityStack* tmpStack = realloc((*stack), entityStack_GetStackAllocSize(stack));
    Entity* tmpStackValues = realloc((*stack)->entities, entityStack_GetItemsAllocSize(stack));

    if(tmpStack == NULL || tmpStackValues == NULL)
    {
      printf("%s", "-=POP entitystack - OUT OF MEMORY=-");
    }

    (*stack) = tmpStack;
    (*stack)->entities = tmpStackValues;

    if(entityStack_Count((*stack)) > 0)
      (*stack)->top = (*stack)->entities[0];
  }
}

Entity entityStack_Peek(EntityStack* stack)
{
  return((*stack).top);
}

int entityStack_GetIndex(EntityStack* stack, Entity entity)
{
  for(int index = 0; index < stack->size; index++)
  {
    if(stack->entities[index].vaoID == entity.vaoID)
      return(index);
  }

  return(-1);
}

void entityStack_Rotate(EntityStack* stack, int rotateN)
{
  int i;
  Entity posNum;

  for(int x = 0; x < rotateN; x++)
  {
    posNum = stack->entities[entityStack_Count(stack) - 1];;

    for(i = entityStack_Count(stack) - 1; i > 0; i--)
    {
      stack->entities[i] = stack->entities[i-1];
    }

    stack->entities[0] = posNum;
  }
}

int entityStack_Count(EntityStack* stack)
{
  return(stack->size);
}

int entityStack_GetStackAllocSize(EntityStack** stack)
{
  return(sizeof(struct EntityStack) + (*stack)->size * sizeof(struct Entity));
}

int entityStack_GetItemsAllocSize(EntityStack** stack)
{
  return((*stack)->size * sizeof(struct Entity));
}

// end EntityStack funcs

// start FloatBuffer funcs

FloatBuffer* new_FloatBufferFromFloatArray(float fillData[], unsigned int size)
{
  FloatBuffer* fBuffer = malloc(sizeof(struct FloatBuffer) + sizeof(float) * size);

  fBuffer->size = size;
  for(unsigned int i = 0; i < size; i++)
  {
    fBuffer->databuffer[i] = fillData[i];
  }

  return(fBuffer);
}

// end FloatBuffer funcs

// start GLubyte funcs

UByteBuffer* new_UByteBufferFromUByteArray(unsigned int fillData[], unsigned int size)
{
  UByteBuffer* UByteBuffer = malloc(sizeof(struct UByteBuffer) + sizeof(unsigned int) * size);

  UByteBuffer->size = size;
  for(unsigned int i = 0; i < size; i++)
  {
    UByteBuffer->databuffer[i] = fillData[i];
  }

  return(UByteBuffer);
}

// end GLubyte funcs

// start planeArray funcs

planeArray* new_planeArray(int size)
{
  planeArray* construct = malloc(sizeof(struct planeArray) + (sizeof(struct Plane) * size) - 1);

  construct->planes = (struct Plane*)calloc(size, sizeof(struct Plane*));
  construct->SIZE = size;

  for(int i = 0; i < size; i++)
  {
    construct->planes[i].distanceToPoint = &calcVec3DistanceToPoint;
  }

  return(construct);
}

int planeArray_Count(planeArray* array)
{
  return(array->SIZE);
}

int planeArray_GetStackAllocSize(planeArray** array)
{
  return(sizeof(struct planeArray) + sizeof(struct Plane) * (*array)->SIZE);
}

int planeArray_GetItemsAllocSize(planeArray** array)
{
  return(sizeof(struct Plane) * (*array)->SIZE);
}

// end planeArray funcs
