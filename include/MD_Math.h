#ifndef MATH_H
#define MATH_H

#include <math.h>

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

#endif