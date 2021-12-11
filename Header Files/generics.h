#ifndef GENERICS_H
#define GENERICS_H

#include <malloc.h>

#include "staticChunkManager.component.h"

#include "commonIncludes.inc.h"
#include "ghostymath.h"
#include "vec3.h"
#include "vec4.h"

typedef struct uIntStack
{
  unsigned int* StackItems;
  unsigned int* top;
  int size;
} uIntStack;

uIntStack* init_UIntStack();

uIntStack* uIntStack_Push(uIntStack* stack, unsigned int item);
uIntStack* uIntStack_Pop(uIntStack* stack);
unsigned int uIntStack_Peek(uIntStack* stack);

void uIntStack_Rotate(uIntStack* stack, int rotateN);
int uIntStack_Count(uIntStack* stack);

int uIntStack_GetStackAllocSize(uIntStack* stack);
int uIntStack_GetItemsAllocSize(uIntStack* stack);

typedef struct Entity
{
  unsigned int vaoID;
  vec3 position;
  vec3 rotation;
  vec3 scale;
  vec3 velocity;
  Mesh mesh;
  int triangleCount;
  int enabledFaces;
} Entity;

typedef struct EntityStack
{
  Entity* entities;
  Entity top;
  int size;
  int (*entityStack_GetIndex)(void*, Entity);
} EntityStack;

EntityStack* init_EntityStack();

void entityStack_Push(EntityStack** stack, Entity* entity);
void entityStack_Pop(EntityStack** stack);
Entity entityStack_Peek(EntityStack* stack);

int entityStack_GetIndex(EntityStack* stack, Entity entity);

void entityStack_Rotate(EntityStack* stack, int rotateN);
int entityStack_Count(EntityStack* stack);

int entityStack_GetStackAllocSize(EntityStack** stack);
int entityStack_GetItemsAllocSize(EntityStack** stack);

typedef struct FloatBuffer
{
  unsigned char size;
  float databuffer[];
} FloatBuffer;

typedef struct UByteBuffer
{
  unsigned char size;
  unsigned char databuffer[];
} UByteBuffer;

FloatBuffer* new_FloatBufferFromFloatArray(float fillData[], unsigned int size);
UByteBuffer* new_UByteBufferFromUByteArray(unsigned int fillData[], unsigned int size);

// start definitions of planeArray

typedef struct Plane
{
    float (*distanceToPoint)(vec3, vec3, float);
    float distanceToOrigin;
    vec3 normal;
} Plane;

typedef struct planeArray
{
  Plane* planes;
  int SIZE;
} planeArray;

planeArray* new_planeArray(int size);

int planeArray_Count(planeArray* array);

int planeArray_GetStackAllocSize(planeArray** array);
int planeArray_GetItemsAllocSize(planeArray** array);

// end definitions of planeArray

// start definition of ViewFrustum



// end definition of ViewFrustum

#endif
