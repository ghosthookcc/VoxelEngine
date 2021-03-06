#include "ghostymath.h"

float calcVec2DotProduct(vec2 vec2A, vec2 vec2B)
{
  return(vec2A.x * vec2B.x + vec2A.y * vec2B.y);
}

float calcVec3DistanceToPoint(vec3 point, vec3 secondVec3, float distanceToOrigin)
{
    return(calcVec3DotProduct(point, secondVec3) + distanceToOrigin);
}

float calcVec3DotProduct(vec3 vec3A, vec3 vec3B)
{
    return(vec3A.x * vec3B.x + vec3A.y * vec3B.y + vec3A.z * vec3B.z);
}

float calcVec3length(vec3 vec3A)
{
    return(sqrtf(vec3A.x * vec3A.x + vec3A.y * vec3A.y + vec3A.z * vec3A.z));
}

vec3 calcVec3CrossProduct(vec3 vec3A, vec3 vec3B)
{
    vec3 new_vec3;

    new_vec3.x = vec3A.y * vec3B.z - vec3A.z * vec3B.y;
    new_vec3.y = vec3A.z * vec3B.x - vec3A.x * vec3B.z;
    new_vec3.z = vec3A.x * vec3B.y - vec3A.y * vec3B.x;

    return(new_vec3);
}

vec3 normalizeVec3(vec3 vec3A)
{
    float length = calcVec3length(vec3A);

    vec3A.x /= length;
    vec3A.y /= length;
    vec3A.z /= length;

    return(vec3A);
}

vec3 multiplyVec3ByVec3(vec3 vec3A, vec3 vec3B)
{
  vec3A.x *= vec3B.x;
  vec3A.y *= vec3B.y;
  vec3A.z *= vec3B.z;

  return vec3A;
}

vec3 multiplyVec3ByFloat(vec3 vec3A, float value)
{
  vec3A.x *= value;
  vec3A.y *= value;
  vec3A.z *= value;

  return vec3A;
}

vec3 addVec3ByVec3(vec3 vec3A, vec3 vec3B)
{
  vec3A.x += vec3B.x;
  vec3A.y += vec3B.y;
  vec3A.z += vec3B.z;

  return vec3A;
}

vec4 addVec3ByVec4(vec3 vec3A, vec4 vec4B)
{
  vec4 new_Vec4 = new_vec4(0.0f, 0.0f, 0.0f, 0.0f);
  new_Vec4.x = vec3A.x + vec4B.x;
  new_Vec4.y = vec3A.y + vec4B.y;
  new_Vec4.z = vec3A.z + vec4B.z;

  return new_Vec4;
}

vec3 addVec3ByFloat(vec3 vec3A, float value)
{
  vec3A.x += value;
  vec3A.y += value;
  vec3A.z += value;

  return(vec3A);
}

vec3 subtractVec3ByVec3(vec3 vec3A, vec3 vec3B)
{
  vec3A.x -= vec3B.x;
  vec3A.y -= vec3B.y;
  vec3A.z -= vec3B.z;

  return(vec3A);
}

vec3 subtractVec3ByFloat(vec3 vec3A, float value)
{
  vec3A.x -= value;
  vec3A.y -= value;
  vec3A.z -= value;

  return(vec3A);
}

vec3 subtractVec3ByVec4(vec3 vec3A, vec4 vec4A)
{
  vec3 new_Vec3 = new_vec3(0.0f, 0.0f, 0.0f);
  new_Vec3.x = vec3A.x - vec4A.x;
  new_Vec3.y = vec3A.y - vec4A.y;
  new_Vec3.z = vec3A.z - vec4A.z;
  return(new_Vec3);
}

vec3 subtractVec4ByVec3(vec4 vec4B, vec3 vec3A)
{
  vec3 new_Vec3 = new_vec3(0.0f, 0.0f, 0.0f);
  new_Vec3.x = vec4B.x - vec3A.x;
  new_Vec3.y = vec4B.y - vec3A.y;
  new_Vec3.z = vec4B.z - vec3A.z;
  return(new_Vec3);
}

vec3 divideVec3(vec3 vec3A, float divideValue)
{
    vec3A.x /= divideValue;
    vec3A.y /= divideValue;
    vec3A.z /= divideValue;

    return(vec3A);
}

dvec3 addDVec3ByDVec3(dvec3 vec3A, dvec3 vec3B)
{
  vec3A.x += vec3B.x;
  vec3A.y += vec3B.y;
  vec3A.z += vec3B.z;

  return vec3A;
}

dvec3 subtractDVec3ByDVec3(dvec3 vec3A, dvec3 vec3B)
{
  vec3A.x -= vec3B.x;
  vec3A.y -= vec3B.y;
  vec3A.z -= vec3B.z;

  return vec3A;
}

dvec3 multiplyDVec3ByDouble(dvec3 vec3A, double value)
{
  vec3A.x *= value;
  vec3A.y *= value;
  vec3A.z *= value;

  return vec3A;
}

dvec3 divideDVec3ByDouble(dvec3 vec3A, double value)
{
  vec3A.x /= value;
  vec3A.y /= value;
  vec3A.z /= value;

  return vec3A;
}

void ResetVec3(vec3* vec3A)
{
  vec3A->x = 0.0f;
  vec3A->y = 0.0f;
  vec3A->z = 0.0f;
}

vec2 GetVec2Const(int value)
{
  int h = value & 3;
  if(h == 0)
  {
    return(new_vec2(1.0f, 1.0f));
  }
  else if (h == 1)
  {
    return(new_vec2(-1.0f, 1.0f));
  }
  else if (h == 2)
  {
    return(new_vec2(-1.0f, -1.0f));
  }
  else
  {
    return(new_vec2(1.0f, -1.0f));
  }
}

vec4 divideVec4(vec4 vec4A, float divideValue)
{
  vec4A.x /= divideValue;
  vec4A.y /= divideValue;
  vec4A.z /= divideValue;
  vec4A.w /= divideValue;

  return(vec4A);
}

void multiplyVec3ByMat4(vec3 vec3A, struct mat4x4* mat4A)
{
  mat4A->matrix[0][0] = mat4A->matrix[0][0] * vec3A.x;
  mat4A->matrix[0][1] = mat4A->matrix[0][1] * vec3A.y;
  mat4A->matrix[0][2] = mat4A->matrix[0][2] * vec3A.z;

  mat4A->matrix[1][0] = mat4A->matrix[1][0] * vec3A.x;
  mat4A->matrix[1][1] = mat4A->matrix[1][1] * vec3A.y;
  mat4A->matrix[1][2] = mat4A->matrix[1][2] * vec3A.z;

  mat4A->matrix[2][0] = mat4A->matrix[2][0] * vec3A.x;
  mat4A->matrix[2][1] = mat4A->matrix[2][1] * vec3A.y;
  mat4A->matrix[2][2] = mat4A->matrix[2][2] * vec3A.z;
}

vec3 multiplyMat4ByVec3(struct mat4x4 mat4A, vec3 vec3A)
{
  vec3 new_Vec3 = new_vec3(0.0f, 0.0f, 0.0f);
  new_Vec3.x = vec3A.x * mat4A.matrix[0][0] + vec3A.y * mat4A.matrix[1][0] + vec3A.z * mat4A.matrix[2][0];
  new_Vec3.y = vec3A.x * mat4A.matrix[0][1] + vec3A.y * mat4A.matrix[1][1] + vec3A.z * mat4A.matrix[2][1];
  new_Vec3.z = vec3A.x * mat4A.matrix[0][2] + vec3A.y * mat4A.matrix[1][2] + vec3A.z * mat4A.matrix[2][2];
  return new_Vec3;
}

vec4 multiplyMat4ByVec4(struct mat4x4 mat4A, vec4 vec4A)
{
  vec4 new_Vec4 = new_vec4(0.0f, 0.0f, 0.0f, 0.0f);
  new_Vec4.x = vec4A.x * mat4A.matrix[0][0] + vec4A.y * mat4A.matrix[1][0] + vec4A.z * mat4A.matrix[2][0] + vec4A.w * mat4A.matrix[3][0];
  new_Vec4.y = vec4A.x * mat4A.matrix[0][1] + vec4A.y * mat4A.matrix[1][1] + vec4A.z * mat4A.matrix[2][1] + vec4A.w * mat4A.matrix[3][1];
  new_Vec4.z = vec4A.x * mat4A.matrix[0][2] + vec4A.y * mat4A.matrix[1][2] + vec4A.z * mat4A.matrix[2][2] + vec4A.w * mat4A.matrix[3][2];
  new_Vec4.w = vec4A.x * mat4A.matrix[0][3] + vec4A.y * mat4A.matrix[1][3] + vec4A.z * mat4A.matrix[2][3] + vec4A.w * mat4A.matrix[3][3];
  return new_Vec4;
}

vec3 vec4ToVec3(vec4 vec4A)
{
  return(new_vec3(vec4A.x, vec4A.y, vec4A.z));
}

vec4 vec3ToVec4(vec3 vec3A)
{
  return(new_vec4(vec3A.x, vec3A.y, vec3A.z, 0.0f));
}

vec3 dvec3ToVec3(dvec3 vec3A)
{
  return(new_vec3((float)vec3A.x, (float)vec3A.y, (float)vec3A.z));
}

struct mat4x4 multiplyVec4ByMat4(vec4 vec4A, struct mat4x4 mat4A)
{
  struct mat4x4 new_Mat4;
  new_Mat4.matrix[0][0] = vec4A.x * mat4A.matrix[0][0];
  new_Mat4.matrix[0][1] = vec4A.y * mat4A.matrix[0][1];
  new_Mat4.matrix[0][2] = vec4A.z * mat4A.matrix[0][2];
  new_Mat4.matrix[0][3] = vec4A.w * mat4A.matrix[0][3];

  new_Mat4.matrix[1][0] = vec4A.x * mat4A.matrix[1][0];
  new_Mat4.matrix[1][1] = vec4A.y * mat4A.matrix[1][1];
  new_Mat4.matrix[1][2] = vec4A.z * mat4A.matrix[1][2];
  new_Mat4.matrix[1][3] = vec4A.w * mat4A.matrix[1][3];

  new_Mat4.matrix[2][0] = vec4A.x * mat4A.matrix[2][0];
  new_Mat4.matrix[2][1] = vec4A.y * mat4A.matrix[2][1];
  new_Mat4.matrix[2][2] = vec4A.z * mat4A.matrix[2][2];
  new_Mat4.matrix[2][3] = vec4A.w * mat4A.matrix[2][3];

  new_Mat4.matrix[3][0] = vec4A.x * mat4A.matrix[3][0];
  new_Mat4.matrix[3][1] = vec4A.y * mat4A.matrix[3][1];
  new_Mat4.matrix[3][2] = vec4A.z * mat4A.matrix[3][2];
  new_Mat4.matrix[3][3] = vec4A.w * mat4A.matrix[3][3];
  return(new_Mat4);
}

struct mat4x4 multiplyMat4ByMat4(struct mat4x4 mat4A, struct mat4x4 mat4B)
{
  struct mat4x4 new_Mat4 = Empty_mat4x4();
  for(int y = 0; y < 4; y++)
  {
    for(int x = 0; x < 4; x++)
    {
      for(int i = 0; i < 4; i++) { new_Mat4.matrix[y][x] += mat4A.matrix[y][i] * mat4B.matrix[i][x]; }
    }
  }
  return(new_Mat4);
}

mat4x4 calcInverseMat4(struct mat4x4 mat4A)
{
  float fA0 = mat4A.matrix[0][0] * mat4A.matrix[1][1] - mat4A.matrix[0][1] * mat4A.matrix[1][0];
	float fA1 = mat4A.matrix[0][0] * mat4A.matrix[1][2] - mat4A.matrix[0][2] * mat4A.matrix[1][0];
	float fA2 = mat4A.matrix[0][0] * mat4A.matrix[1][3] - mat4A.matrix[0][3] * mat4A.matrix[1][0];

  float fA3 = mat4A.matrix[0][1] * mat4A.matrix[1][2] - mat4A.matrix[0][2] * mat4A.matrix[1][1];
	float fA4 = mat4A.matrix[0][1] * mat4A.matrix[1][3] - mat4A.matrix[0][3] * mat4A.matrix[1][1];
	float fA5 = mat4A.matrix[0][2] * mat4A.matrix[1][3] - mat4A.matrix[0][3] * mat4A.matrix[1][2];

  float fB0 = mat4A.matrix[2][0] * mat4A.matrix[3][1] - mat4A.matrix[2][1] * mat4A.matrix[3][0];
	float fB1 = mat4A.matrix[2][0] * mat4A.matrix[3][2] - mat4A.matrix[2][2] * mat4A.matrix[3][0];
	float fB2 = mat4A.matrix[2][0] * mat4A.matrix[3][3] - mat4A.matrix[2][3] * mat4A.matrix[3][0];

  float fB3 = mat4A.matrix[2][1] * mat4A.matrix[3][2] - mat4A.matrix[2][2] * mat4A.matrix[3][1];
	float fB4 = mat4A.matrix[2][1] * mat4A.matrix[3][3] - mat4A.matrix[2][3] * mat4A.matrix[3][1];
	float fB5 = mat4A.matrix[2][2] * mat4A.matrix[3][3] - mat4A.matrix[2][3] * mat4A.matrix[3][2];

  float fDet = fA0 * fB5 - fA1 * fB4 + fA2 * fB3 + fA3 * fB2 - fA4 * fB1 + fA5 * fB0;

  struct mat4x4 invertedMat4;

  invertedMat4.matrix[0][0] = mat4A.matrix[1][1] * fB5 - mat4A.matrix[1][2] * fB4 + mat4A.matrix[1][3] * fB3;
  invertedMat4.matrix[0][1] = -mat4A.matrix[0][1] * fB5 + mat4A.matrix[0][2] * fB4 - mat4A.matrix[0][3] * fB3;
	invertedMat4.matrix[0][2] = mat4A.matrix[3][1] * fA5 - mat4A.matrix[3][2] * fA4 + mat4A.matrix[3][3] * fA3;
	invertedMat4.matrix[0][3] = -mat4A.matrix[2][1] * fA5 + mat4A.matrix[2][2] * fA4 - mat4A.matrix[2][3] * fA3;

  invertedMat4.matrix[1][0] = -mat4A.matrix[1][0] * fB5 + mat4A.matrix[1][2] * fB2 - mat4A.matrix[1][3] * fB1;
	invertedMat4.matrix[1][1] = mat4A.matrix[0][0] * fB5 - mat4A.matrix[0][2] * fB2 + mat4A.matrix[0][3] * fB1;
	invertedMat4.matrix[1][2] = -mat4A.matrix[3][0] * fA5 + mat4A.matrix[3][2] * fA2 - mat4A.matrix[3][3] * fA1;
	invertedMat4.matrix[1][3] = mat4A.matrix[2][0] * fA5 - mat4A.matrix[2][2] * fA2 + mat4A.matrix[2][3] * fA1;

	invertedMat4.matrix[2][0] = mat4A.matrix[1][0] * fB4 - mat4A.matrix[1][1] * fB2 + mat4A.matrix[1][3] * fB0;
	invertedMat4.matrix[2][1] = -mat4A.matrix[0][0] * fB4 + mat4A.matrix[0][1] * fB2 - mat4A.matrix[0][3] * fB0;
	invertedMat4.matrix[2][2] = mat4A.matrix[3][0] * fA4 - mat4A.matrix[3][1] * fA2 + mat4A.matrix[3][3] * fA0;
	invertedMat4.matrix[2][3] = -mat4A.matrix[2][0] * fA4 + mat4A.matrix[2][1] * fA2 - mat4A.matrix[2][3] * fA0;

	invertedMat4.matrix[3][0] = -mat4A.matrix[1][0] * fB3 + mat4A.matrix[1][1] * fB1 - mat4A.matrix[1][2] * fB0;
	invertedMat4.matrix[3][1] = mat4A.matrix[0][0] * fB3 - mat4A.matrix[0][1] * fB1 + mat4A.matrix[0][2] * fB0;
	invertedMat4.matrix[3][2] = -mat4A.matrix[3][0] * fA3 + mat4A.matrix[3][1] * fA1 - mat4A.matrix[3][2] * fA0;
	invertedMat4.matrix[3][3] = mat4A.matrix[2][0] * fA3 - mat4A.matrix[2][1] * fA1 + mat4A.matrix[2][2] * fA0;

  float fInvDet = ((float)1.0) / fDet;
  for(unsigned int row = 0; row < 4; row++)
  {
    for(unsigned int column = 0; column < 4; column++)
    {
      invertedMat4.matrix[row][column] *= fInvDet;
    }
  }

  return(invertedMat4);
}

vec3 getNegativeVec3(vec3 vec3A)
{
  vec3A.x = -vec3A.x;
  vec3A.y = -vec3A.y;
  vec3A.z = -vec3A.z;

  return(vec3A);
}

quaternion multiplyQuaternionByQuaternion(quaternion quaternionA, quaternion quaternionB)
{
  float x =  quaternionA.x * quaternionB.angle + quaternionA.y * quaternionB.z - quaternionA.z * quaternionB.y + quaternionA.angle * quaternionB.x;
  float y = -quaternionA.x * quaternionB.z + quaternionA.y * quaternionB.angle + quaternionA.z * quaternionB.x + quaternionA.angle * quaternionB.y;
  float z =  quaternionA.x * quaternionB.y - quaternionA.y * quaternionB.x + quaternionA.z * quaternionB.angle + quaternionA.angle * quaternionB.z;
  float w = -quaternionA.x * quaternionB.x - quaternionA.y * quaternionB.y - quaternionA.z * quaternionB.z + quaternionA.angle * quaternionB.angle;

  return(new_Quaternion(x, y, z, w));
}

vec3 multiplyQuaternionByVec3(quaternion quaternionA, vec3 point3d)
{
  float x = quaternionA.x * 2.0f;
  float y = quaternionA.y * 2.0f;
  float z = quaternionA.z * 2.0f;

  float x_x = quaternionA.x * x;
  float y_y = quaternionA.y * y;
  float z_z = quaternionA.z * z;

  float x_y = quaternionA.x * y;
  float x_z = quaternionA.x * z;
  float y_z = quaternionA.y * z;

  float w_x = quaternionA.angle * x;
  float w_y = quaternionA.angle * y;
  float w_z = quaternionA.angle * z;

  vec3 resPoint3d;

  resPoint3d.x = (1.0f - (y_y + z_z)) * point3d.x + (x_y - w_z) * point3d.y + (x_z + w_y) * point3d.z;
  resPoint3d.y = (x_y + w_z) * point3d.x + (1.0f - (x_x + z_z)) * point3d.y + (y_z - w_x) * point3d.z;
  resPoint3d.z = (x_z - w_y) * point3d.x + (y_z + w_x) * point3d.y + (1.0f - (x_x + y_y)) * point3d.z;

  return(resPoint3d);
}

void getAxisAngle(quaternion* quaternionA, vec3 axis, float angle)
{
  vec3 axisN = normalizeVec3(axis);
  float sin_a_2 = (float)sin(angle * GHOSTYMATH_PI / 360.0f);

  quaternionA->x = axisN.x * sin_a_2;
  quaternionA->y = axisN.y * sin_a_2;
  quaternionA->z = axisN.z * sin_a_2;

  quaternionA->angle = (float)cos(angle * GHOSTYMATH_PI / 360.0f);
}

void quaternionToMat4Rotation(quaternion quaternionA, struct mat4x4* dst)
{
  dst->matrix[0][0] = (1.0f - 2.0f * quaternionA.y * quaternionA.y - 2.0f * quaternionA.z * quaternionA.z);
  dst->matrix[0][1] = (2.0f * quaternionA.x * quaternionA.y - 2.0f * quaternionA.z * quaternionA.angle);
  dst->matrix[0][2] = (2.0f * quaternionA.x * quaternionA.z + 2.0f * quaternionA.y * quaternionA.angle);

  dst->matrix[1][0] = (2.0f * quaternionA.x * quaternionA.y + 2.0f * quaternionA.z * quaternionA.angle);
  dst->matrix[1][1] = (1.0f - 2.0f * quaternionA.x * quaternionA.x - 2.0f * quaternionA.z * quaternionA.z);
  dst->matrix[1][2] = (2.0f * quaternionA.y * quaternionA.z - 2.0f * quaternionA.x * quaternionA.angle);

  dst->matrix[2][0] = (2.0f * quaternionA.x * quaternionA.z - 2.0f * quaternionA.y * quaternionA.angle);
  dst->matrix[2][1] = (2.0f * quaternionA.y * quaternionA.z + 2.0f * quaternionA.x * quaternionA.angle);
  dst->matrix[2][2] = (1.0f - 2.0f * quaternionA.x * quaternionA.x - 2.0f * quaternionA.y * quaternionA.y);

  dst->matrix[3][3] = 1.0f;
}

float calcQuaternionlength(quaternion quaternionA)
{
  return(sqrtf(quaternionA.x * quaternionA.x +
               quaternionA.y * quaternionA.y +
               quaternionA.z * quaternionA.z +
               quaternionA.angle * quaternionA.angle));
}

quaternion normalizeQuaternion(quaternion quaternionA)
{
  float length = calcQuaternionlength(quaternionA);

  quaternionA.x /= length;
  quaternionA.y /= length;
  quaternionA.z /= length;
  quaternionA.angle /= length;

  return(quaternionA);
}

quaternion getQuaternionConjugate(quaternion quaternionA)
{
  quaternion new_Quaternion;

  new_Quaternion.x = -quaternionA.x;
  new_Quaternion.y = -quaternionA.y;
  new_Quaternion.z = -quaternionA.z;
  new_Quaternion.angle = quaternionA.angle;

  return(new_Quaternion);
}

double calcArrayByDoubleDot(int g[], double x, double y)
{
  return(g[0] * x + g[1] * y);
}

int calcFastfloor(double x)
{
  return(x > 0 ? (int)(x) : (int)(x - 1));
}

dvec3 calcDistanceDVec3(dvec3 vec3A, dvec3 vec3B)
{
    dvec3 new_vec3A = subtractDVec3ByDVec3(vec3A, vec3B);
    return(new_vec3A);
}

double calcDistanceSum(dvec3 vec3A, dvec3 vec3B)
{
    dvec3 stg1 = calcDistanceDVec3(vec3A, vec3B);
    return(sqrt(pow(stg1.x, 2) + pow(stg1.y, 2) + pow(stg1.z, 2)));
}

dvec3 calcAccelerationVec3(dvec3 vec3A, body target)
{
    double first_arg = GRAV_CONST * target.mass;

    dvec3 dist = subtractDVec3ByDVec3(target.position, vec3A);
    double mag = pow(calcDistanceSum(vec3A, target.position), 3);

    return(divideDVec3ByDouble(multiplyDVec3ByDouble(dist, first_arg), mag));
}

dvec3 calcAccelLoop(dvec3 origin, struct blist bodylist, unsigned int bid)
{
  dvec3 accel_velocity = new_dvec3(0.0, 0.0, 0.0);
  for(unsigned int i = 0; i < bodylist.size; i++)
  {
    if(bodylist.planets[i].bid == bid) { continue; }

    accel_velocity = addDVec3ByDVec3(accel_velocity, calcAccelerationVec3(origin, bodylist.planets[i]));
  }

  return(accel_velocity);
}

double calcDVec3DotProduct(dvec3 vec3A, dvec3 vec3B)
{
    return(vec3A.x * vec3B.x + vec3A.y * vec3B.y + vec3A.z * vec3B.z);
}

double calcDVec3length(dvec3 vec3A)
{
    return(sqrtf(vec3A.x * vec3A.x + vec3A.y * vec3A.y + vec3A.z * vec3A.z));
}

dvec3 calcDVec3CrossProduct(dvec3 vec3A, dvec3 vec3B)
{
    dvec3 new_vec3;

    new_vec3.x = vec3A.y * vec3B.z - vec3A.z * vec3B.y;
    new_vec3.y = vec3A.z * vec3B.x - vec3A.x * vec3B.z;
    new_vec3.z = vec3A.x * vec3B.y - vec3A.y * vec3B.x;

    return(new_vec3);
}

dvec3 getDVec3SpecAngularMomentum(dvec3 position, dvec3 velocity)
{
  return calcDVec3CrossProduct(position, velocity);
}

double getGravParam(double mass)
{
  return GRAV_CONST * mass;
}


