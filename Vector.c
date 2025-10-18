#include <MD_Math.h>
#include <Constant.h>

mdVec2 Vec2Add(mdVec2 v1, mdVec2 v2)
{
    mdVec2 result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
}

mdVec3 Vec3Add(mdVec3 v1, mdVec3 v2)
{
    mdVec3 result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

mdVec4 Vec4Add(mdVec4 v1, mdVec4 v2)
{
    mdVec4 result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    result.w = v1.w + v2.w;
    return result;
}

mdVec2 Vec2Minus(mdVec2 v1, mdVec2 v2)
{
    mdVec2 result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    return result;
}

mdVec3 Vec3Minus(mdVec3 v1, mdVec3 v2)
{
    mdVec3 result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

mdVec4 Vec4Minus(mdVec4 v1, mdVec4 v2)
{
    mdVec4 result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    result.w = v1.w - v2.w;
    return result;
}

mdVec2 MulVec2(float lambda, mdVec2 v)
{
    mdVec2 result;
    result.x = lambda * v.x;
    result.y = lambda * v.y;
    return result;
}

mdVec3 MulVec3(float lambda, mdVec3 v)
{
    mdVec3 result;
    result.x = lambda * v.x;
    result.y = lambda * v.y;
    result.z = lambda * v.z;
    return result;
}

mdVec4 MulVec4(float lambda, mdVec4 v)
{
    mdVec4 result;
    result.x = lambda * v.x;
    result.y = lambda * v.y;
    result.z = lambda * v.z;
    result.w = lambda * v.w;
    return result;
}

float Vec2Dot(mdVec2 v1, mdVec2 v2)
{
    return v1.x * v2.x +
            v1.y * v2.y;
}

float Vec3Dot(mdVec3 v1, mdVec3 v2)
{
    return v1.x * v2.x +
            v1.y * v2.y +
             v1.z * v2.z;
}

float Vec4Dot(mdVec4 v1, mdVec4 v2)
{
    return v1.x * v2.x +
            v1.y * v2.y +
             v1.z * v2.z +
              v1.w * v2.w;
}

int Vec2Equal(mdVec2 v1, mdVec2 v2)
{
    return (
        MD_Equal(v1.x, v2.x) &&
        MD_Equal(v1.y, v2.y)
    ) ? MD_TRUE : MD_FALSE;
}

int Vec3Equal(mdVec3 v1, mdVec3 v2)
{
    return (
        MD_Equal(v1.x, v2.x) &&
        MD_Equal(v1.y, v2.y) &&
        MD_Equal(v1.z, v2.z)
    ) ? MD_TRUE : MD_FALSE;
}

int Vec4Equal(mdVec4 v1, mdVec4 v2)
{
    return (
        MD_Equal(v1.x, v2.x) &&
        MD_Equal(v1.y, v2.y) &&
        MD_Equal(v1.z, v2.z) &&
        MD_Equal(v1.w, v2.w)
    ) ? MD_TRUE : MD_FALSE;
}

mdVec3 VecCross(mdVec3 v1, mdVec3 v2)
{
    mdVec3 result;
    result.x = v1.y * v2.z - v2.y * v1.z;
    result.y = v1.z * v2.x - v2.z * v1.x;
    result.z = v1.x * v2.y - v2.x * v1.y;
    return result;
}

mdVec2 Vec2Mix(mdVec2 x, mdVec2 y, float a)
{
    return Vec2Add(MulVec2((1.0 - a), x) ,MulVec2(a, y));
}

mdVec3 Vec3Mix(mdVec3 x, mdVec3 y, float a)
{
    return Vec3Add(MulVec3((1.0 - a), x) ,MulVec3(a, y));
}

mdVec4 Vec4Mix(mdVec4 x, mdVec4 y, float a)
{
    return Vec4Add(MulVec4((1.0 - a), x) ,MulVec4(a, y));
}

float Vec2Len(mdVec2 v)
{
    return MD_Hypot(v.x, v.y);
}

float Vec3Len(mdVec3 v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

float Vec4Len(mdVec4 v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

mdVec2 Vec2Norm(mdVec2 v)
{
    mdVec2 result;
    float v_len = 1.0f / Vec2Len(v);
    result.x = v.x * v_len;
    result.y = v.y * v_len;
    return result;
}

mdVec3 Vec3Norm(mdVec3 v)
{
    mdVec3 result;
    float v_len = 1.0f / Vec3Len(v);
    result.x = v.x * v_len;
    result.y = v.y * v_len;
    result.z = v.z * v_len;
    return result;
}

mdVec4 Vec4Norm(mdVec4 v)
{
    mdVec4 result;
    float v_len = 1.0f / Vec4Len(v);
    result.x = v.x * v_len;
    result.y = v.y * v_len;
    result.z = v.z * v_len;
    result.w = v.w * v_len;
    return result;
}

float ProjOfVec2(mdVec2 v1, mdVec2 v2)
{
    return Vec2Dot(v1, v2) / Vec2Len(v2);
}

float ProjOfVec3(mdVec3 v1, mdVec3 v2)
{
    return Vec3Dot(v1, v2) / Vec3Len(v2);
}

float ProjOfVec4(mdVec4 v1, mdVec4 v2)
{
    return Vec4Dot(v1, v2) / Vec4Len(v2);
}

mdVec2 ProjVec2(mdVec2 v1, mdVec2 v2)
{
    mdVec2 result;
    result = MulVec2(ProjOfVec2(v1, v2), Vec2Norm(v2));
    return result;
}

mdVec3 ProjVec3(mdVec3 v1, mdVec3 v2)
{
    mdVec3 result;
    result = MulVec3(ProjOfVec3(v1, v2), Vec3Norm(v2));
    return result;
}

mdVec4 ProjVec4(mdVec4 v1, mdVec4 v2)
{
    mdVec4 result;
    result = MulVec4(ProjOfVec4(v1, v2), Vec4Norm(v2));
    return result;
}