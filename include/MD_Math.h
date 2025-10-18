#ifndef MATH_H
#define MATH_H

#include <math.h>
#include "MD_Vector.h"
#include "MD_Matrix.h"

float MD_Abs(float x);
int MD_Factorial(int x);
float MD_Rsqrt(float x);
float MD_Log2(float x);
float MD_Max(float a, float b);
float MD_Min(float a, float b);
float MD_Hypot(float x, float y);
float MD_Cbrt(float x);
float MD_Expml(float x);
float MD_Lnlp(float x);
float MD_Tan(float x);
float MD_ArSinh(float x);
float MD_ArCosh(float x);
float MD_ArTanh(float x);
int MD_Trunc(float x);
int MD_Round(float x);
int MD_Isfinite(float x);
int MD_IsInf(float x);
int MD_IsNaN(float x);
int MD_IsNormal(float x);
int MD_Signbit(float x);
int MD_Equal(float a, float b);
float MD_ToRadian(float angle);
float MD_ToAngle(float radian);
float MD_Mix(float x, float y, float a);

mdVec2 Vec2Add(mdVec2 v1, mdVec2 v2);
mdVec3 Vec3Add(mdVec3 v1, mdVec3 v2);
mdVec4 Vec4Add(mdVec4 v1, mdVec4 v2);

mdVec2 Vec2Minus(mdVec2 v1, mdVec2 v2);
mdVec3 Vec3Minus(mdVec3 v1, mdVec3 v2);
mdVec4 Vec4Minus(mdVec4 v1, mdVec4 v2);

mdVec2 MulVec2(float lambda, mdVec2 v);
mdVec3 MulVec3(float lambda, mdVec3 v);
mdVec4 MulVec4(float lambda, mdVec4 v);

float Vec2Dot(mdVec2 v1, mdVec2 v2);
float Vec3Dot(mdVec3 v1, mdVec3 v2);
float Vec4Dot(mdVec4 v1, mdVec4 v2);

int Vec2Equal(mdVec2 v1, mdVec2 v2);
int Vec3Equal(mdVec3 v1, mdVec3 v2);
int Vec4Equal(mdVec4 v1, mdVec4 v2);

mdVec3 VecCross(mdVec3 v1, mdVec3 v2);

mdVec2 Vec2Mix(mdVec2 x, mdVec2 y, float a);
mdVec3 Vec3Mix(mdVec3 x, mdVec3 y, float a);
mdVec4 Vec4Mix(mdVec4 x, mdVec4 y, float a);

float Vec2Len(mdVec2 v);
float Vec3Len(mdVec3 v);
float Vec4Len(mdVec4 v);

mdVec2 Vec2Norm(mdVec2 v);
mdVec3 Vec3Norm(mdVec3 v);
mdVec4 Vec4Norm(mdVec4 v);

float ProjOfVec2(mdVec2 v1, mdVec2 v2);
float ProjOfVec3(mdVec3 v1, mdVec3 v2);
float ProjOfVec4(mdVec4 v1, mdVec4 v2);

mdVec2 ProjVec2(mdVec2 v1, mdVec2 v2);
mdVec3 ProjVec3(mdVec3 v1, mdVec3 v2);
mdVec4 ProjVec4(mdVec4 v1, mdVec4 v2);
#endif