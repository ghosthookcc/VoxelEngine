#ifndef GHOSTY_MATH_H
#define GHOSTY_MATH_H

#include <math.h>
#include <windows.h>
#include <gl/gl.h>
#include <stdio.h>

#include "configurations/bodies.h"

#include "staticRenderingVars.component.h"

#include "generics.h"
#include "quaternion.h"
#include "matrix.h"
#include "vec4.h"
#include "vec3.h"
#include "vec2.h"

#ifndef MATH_MACROS
#define GHOSTYMATH_PI 3.14159265358979323846264338327950288
#define GRAV_CONST 6.67408e-11
#define degreesToRadians(angleInDegrees) ((angleInDegrees) * GHOSTYMATH_PI / 180.0)
#define radiansToDegrees(angleInRadians) ((angleInRadians) * 180.0 / GHOSTYMATH_PI)
#endif

typedef struct
{
  float pitch;
  float yaw;
  float roll;
} cameraOrientations;

typedef struct Camera
{
  vec3 EYE;
  cameraOrientations ROTATION;
} Camera;

enum AllPlanes
{
    Near = 0,
    Far = 1,
    Left = 2,
    Right = 3,
    Top = 4,
    Bottom = 5
};

float calcVec2DotProduct(vec2 vec2A, vec2 vec2B);

float calcVec3DistanceToPoint(vec3 point, vec3 secondVec3, float distanceToOrigin);

float calcVec3DotProduct(vec3 vec3A, vec3 vec3B);

float calcVec3length(vec3 vec3A);

vec3 calcVec3CrossProduct(vec3 vec3A, vec3 vec3B);

vec3 normalizeVec3(vec3 vec3A);

vec3 multiplyVec3ByVec3(vec3 vec3A, vec3 vec3B);
vec3 multiplyVec3ByFloat(vec3 vec3A, float value);

vec3 addVec3ByVec3(vec3 vec3A, vec3 vec3B);
vec4 addVec3ByVec4(vec3 vec3A, vec4 vec4B);
vec3 addVec3ByFloat(vec3 vec3A, float value);

vec3 subtractVec3ByVec3(vec3 vec3A, vec3 vec3B);
vec3 subtractVec3ByVec4(vec3 vec3A, vec4 vec4A);
vec3 subtractVec4ByVec3(vec4 vec4B, vec3 vec3A);

vec3 divideVec3(vec3 vec3A, float divideValue);

void ResetVec3(vec3* vec3A);

vec2 GetVec2Const(int value);

vec4 divideVec4(vec4 vec4A, float divideValue);

void multiplyVec3ByMat4(vec3 vec3A, struct mat4x4* mat4A);
vec3 multiplyMat4ByVec3(struct mat4x4 mat4A, vec3 vec3A);

struct mat4x4 multiplyVec4ByMat4(vec4 vec4A, struct mat4x4 mat4A);
vec4 multiplyMat4ByVec4(struct mat4x4 mat4A, vec4 vec4A);

vec3 vec4ToVec3(vec4 vec4A);
vec4 vec3ToVec4(vec3 vec3A);

struct mat4x4 multiplyMat4ByMat4(struct mat4x4 mat4A, struct mat4x4 mat4B);

struct mat4x4 calcInverseMat4(struct mat4x4 mat4A);

vec3 getNegativeVec3(vec3 vec3A);

vec3 getVec3Equivelent(vec3 vec3A, vec3 vec3B);

quaternion multiplyQuaternionByQuaternion(quaternion quaternionA, quaternion quaternionB);
vec3 multiplyQuaternionByVec3(quaternion quaternionA, vec3 point3d);

void getAxisAngle(quaternion* quaternionA, vec3 axis, float angle);

void quaternionToMat4Rotation(quaternion quaternionA, struct mat4x4* dst);

float calcQuaternionlength(quaternion quaternionA);

quaternion normalizeQuaternion(quaternion quaternionA);

quaternion getQuaternionConjugate(quaternion quaternionA);

double calcArrayByDoubleDot(int g[], double x, double y);

int calcFastfloor(double x);

dvec3 calcDistanceDVec3(dvec3 vec3A, dvec3 vec3B);

double calcDistanceSum(dvec3 vec3A, dvec3 vec3B);

dvec3 calcAccelerationVec3(dvec3 vec3A, body target);

dvec3 calcAccelLoop(dvec3 origin, struct bodies bodylist, unsigned int bid);

dvec3 addDVec3ByDVec3(dvec3 vec3A, dvec3 vec3B);

dvec3 subtractDVec3ByDVec3(dvec3 vec3A, dvec3 vec3B);

dvec3 multiplyDVec3ByDouble(dvec3 vec3A, double value);

dvec3 divideDVec3ByDouble(dvec3 vec3A, double value);

#endif
