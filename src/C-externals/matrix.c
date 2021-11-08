#include "matrix.h"

// define static vars & constant vars
static const int   int_emptySpaceVal   = 21222399;
static const float float_emptySpaceVal = 0.7799001f;

// start mat4x4 functions

mat4x4 Identity_mat4x4()
{
  mat4x4 new_Mat4x4;

  new_Mat4x4.matrix[0][0] = 1.0f;
  new_Mat4x4.matrix[1][1] = 1.0f;
  new_Mat4x4.matrix[2][2] = 1.0f;
  new_Mat4x4.matrix[3][3] = 1.0f;

  return new_Mat4x4;
}

mat4x4 Empty_mat4x4()
{
  mat4x4 new_Mat4x4;

  for(int y = 0; y < 4; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      new_Mat4x4.matrix[y][x] = 0.0f;
    }
  }

  return new_Mat4x4;
}

void Identity_existingMat4x4(mat4x4* mat4)
{
  mat4->matrix[0][0] = 1.0f;
  mat4->matrix[1][1] = 1.0f;
  mat4->matrix[2][2] = 1.0f;
  mat4->matrix[3][3] = 1.0f;
}

void storeMat4InFloatArray(mat4x4 mat4, float fArray[])
{
  fArray[0] = mat4.matrix[0][0];
  fArray[1] = mat4.matrix[0][1];
  fArray[2] = mat4.matrix[0][2];
  fArray[3] = mat4.matrix[0][3];

  fArray[4] = mat4.matrix[1][0];
  fArray[5] = mat4.matrix[1][1];
  fArray[6] = mat4.matrix[1][2];
  fArray[7] = mat4.matrix[1][3];

  fArray[8] = mat4.matrix[2][0];
  fArray[9] = mat4.matrix[2][1];
  fArray[10] = mat4.matrix[2][2];
  fArray[11] = mat4.matrix[2][3];

  fArray[12] = mat4.matrix[3][0];
  fArray[13] = mat4.matrix[3][1];
  fArray[14] = mat4.matrix[3][2];
  fArray[15] = mat4.matrix[3][3];
}

// end mat4x4 functions

// start mat3x3 functions

mat3x3 Identity_mat3x3()
{
  mat3x3 new_Mat3x3;

  new_Mat3x3.matrix[0][0] = 1.0f;
  new_Mat3x3.matrix[1][1] = 1.0f;
  new_Mat3x3.matrix[2][2] = 1.0f;

  return new_Mat3x3;
}

mat3x3 Empty_mat3x3()
{
  mat3x3 new_Mat3x3;

  for(int y = 0; y < 4; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      new_Mat3x3.matrix[y][x] = 0.0f;
    }
  }

  return new_Mat3x3;
}

void Identity_existingMat3x3(mat3x3* mat3)
{
  mat3->matrix[0][0] = 1.0f;
  mat3->matrix[1][1] = 1.0f;
  mat3->matrix[2][2] = 1.0f;
}

void storeMat3InFloatArray(mat3x3 mat3, float fArray[])
{
  fArray[0] = mat3.matrix[0][0];
  fArray[1] = mat3.matrix[0][1];
  fArray[2] = mat3.matrix[0][2];
  fArray[3] = mat3.matrix[0][3];

  fArray[4] = mat3.matrix[1][0];
  fArray[5] = mat3.matrix[1][1];
  fArray[6] = mat3.matrix[1][2];
  fArray[7] = mat3.matrix[1][3];

  fArray[8] = mat3.matrix[2][0];
  fArray[9] = mat3.matrix[2][1];
  fArray[10] = mat3.matrix[2][2];
  fArray[11] = mat3.matrix[2][3];
}

// end mat3x3 functions

// start mat2x2 functions

mat2x2 Identity_mat2x2()
{
  mat2x2 new_Mat2x2;

  new_Mat2x2.matrix[0][0] = 1.0f;
  new_Mat2x2.matrix[1][1] = 1.0f;

  return new_Mat2x2;
}

mat2x2 Empty_mat2x2()
{
  mat2x2 new_Mat2x2;

  for(int y = 0; y < 4; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      new_Mat2x2.matrix[y][x] = 0.0f;
    }
  }

  return new_Mat2x2;
}

void Identity_existingMat2x2(mat2x2* mat2)
{
  mat2->matrix[0][0] = 1.0f;
  mat2->matrix[1][1] = 1.0f;
}

void storeMat2InFloatArray(mat2x2 mat2, float fArray[])
{
  fArray[0] = mat2.matrix[0][0];
  fArray[1] = mat2.matrix[0][1];
  fArray[2] = mat2.matrix[0][2];
  fArray[3] = mat2.matrix[0][3];

  fArray[4] = mat2.matrix[1][0];
  fArray[5] = mat2.matrix[1][1];
  fArray[6] = mat2.matrix[1][2];
  fArray[7] = mat2.matrix[1][3];
}

// end mat2x2 functions
