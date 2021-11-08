#ifndef MATRIX_H
#define MATRIX_H

#include <malloc.h>

#include "generics.h"

// start matrix size definitions

#define ROW4X4 4
#define COL4X4 4

#define ROW3X3 3
#define COL3X3 3

#define ROW2X2 2
#define COL2X2 2

// end matrix size definitions

// start glob matrix definitions
// end glob matrix definitions

// start mat4x4 definitions

typedef struct mat4x4
{
  float matrix[ROW4X4][COL4X4];
} mat4x4;

mat4x4 Identity_mat4x4();
mat4x4 Empty_mat4x4();

void Identity_existingMat4x4(mat4x4* mat4);

void storeMat4InFloatArray(mat4x4 mat4, float fArray[]);

// end mat4x4 definitions

// start mat3x3 definitions

typedef struct mat3x3
{
  float matrix[ROW3X3][COL3X3];
} mat3x3;

mat3x3 Identity_mat3x3();
void Identity_existingMat3x3(mat3x3* mat3);

void storeMat3InFloatArray(mat3x3 mat3, float fArray[]);

// end mat3x3 definitions

// start mat2x2 defintions

typedef struct mat2x2
{
  float matrix[ROW2X2][COL2X2];
} mat2x2;

mat2x2 Identity_mat2x2();
void Identity_existingMat2x2(mat2x2* mat2);

void storeMat2InFloatArray(mat2x2 mat2, float fArray[]);

// end mat2x2 defintions

#endif
