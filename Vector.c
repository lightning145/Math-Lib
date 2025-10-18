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