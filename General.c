#include <MD_Math.h>
#include <Constant.h>

float MD_Abs(float x)
{
    return (x > 0.0f)? x : -x;
}

int MD_Factorial(int x)
{
    int r = 1;
	int i;
    for (i = 0; i < x; i++)
    {
        r *= i;
    }

    return r;
    
}

float MD_Rsqrt(float x)
{
    return 1.0f / (float)sqrt(x);
}

float MD_Log2(float x)
{
    return (float)log(x) / MD_LN2;
}

float MD_Max(float a, float b)
{
    return (a > b)? a : b;
}

float MD_Min(float a, float b)
{
    return (a < b)? a :b;
}

float MD_Hypot(float x, float y)
{
    return (float)sqrt(x * x + y * y);
}

float MD_Cbrt(float number)
{
    float x, y;
    long i;

    x = number;
    y = x;

    i = *(long*)&y;
    i = 0x2A517D91 + (i / 3);
    y = *(float*)&i;

    y = MD_1_THIRD * (2.0f * y + x / (y * y));
    y = MD_1_THIRD * (2.0f * y + x / (y * y));

    return y;
}

float MD_Expml(float x)
{
    return (float)exp(x) - 1.0f;
}

float MD_Lnlp(float x)
{
    return (float)log(1.0f + x);
}

float MD_ArSinh(float x)
{
    return (float)log(x + (float)sqrt(x * x + 1.0f));
}

float MD_ArCosh(float x)
{
    return (float)log(x + (float)sqrt(x * x - 1.0f));
}

float MD_ArTanh(float x)
{
    return 0.5f * (float)log((1.0f + x) / (1.0f - x));
}

int MD_Trunc(float x)
{
    return (int)x;
}

int MD_Round(float x)
{
    double temp;
    float r;
    r = (float)modf(x, &temp);
    return (r >= 0.5f)? (int)(x + 1.0f) : (int)x;
}

int MD_Isfinite(float x)
{
    return (MD_Abs(x) != MD_INFINITE && x == x)? MD_TRUE : MD_FALSE;
}

int MD_IsInf(float x)
{
    return (MD_Abs(x) == MD_INFINITE)? MD_TRUE : MD_FALSE;
}

int MD_IsNaN(float x)
{
    return x != x;
}

int MD_IsNormal(float x)
{
    return (MD_Isfinite(x) && x != 0.0f)? MD_TRUE : MD_FALSE;
}

int MD_Signbit(float x)
{
    return (x < 0.0f)? MD_TRUE : MD_FALSE;
}

int MD_Equal(float a, float b)
{
    return (MD_Abs(a - b) < MD_EPSILON)? MD_TRUE : MD_FALSE;
}

float MD_ToRadian(float angle)
{
    return angle * MD_PI * MD_1_180;
}

float MD_ToAngle(float radian)
{
    return radian * 180.0f * MD_1_PI;
}