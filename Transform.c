#include <MD_Math.h>
#include <Constant.h>
#include <stdio.h>

mdMat ScaleMatrix(mdVec3 scale)
{
    mdMat m = {
        scale.x, 0.0f, 0.0f ,0.0f,
        0.0f, scale.y, 0.0f, 0.0f,
        0.0f, 0.0f, scale.z, 0.0f, 
        0.0f, 0.0f, 0.0f, 1.0f
    };
    return m;
}

mdMat TranslationMatrix(mdVec3 pos)
{
    mdMat m = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f ,0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        pos.x, pos.y, pos.z, 1.0f
    };

    return m;
}

mdMat RotationXMatrix(float angle)
{
    mdMat m = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, cos(angle), sin(angle), 0.0f,
        0.0f, -sin(angle), cos(angle), 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    return m;
}

mdMat RotationYMatrix(float angle)
{
    mdMat m = {
        cos(angle), 0.0f, -sin(angle), 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        sin(angle), 0.0f, cos(angle), 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    return m;
}

mdMat RotationZMatrix(float angle)
{
    mdMat m = {
        cos(angle), sin(angle), 0.0f, 0.0f,
        -sin(angle), cos(angle), 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    return m;
}

mdMat ViewMatrixRH(mdVec3 Pos,
               mdVec3 Front,
               mdVec3 Up)
{
    Front.x = -Front.x; Front.y = -Front.y; Front.z = -Front.z;
    mdVec3 Direction = Vec3Norm(Front);
    mdVec3 Right = Vec3Norm(VecCross(Up, Direction));
    Up = Vec3Norm(VecCross(Direction, Right));

    mdMat out;

    out._11 = Right.x;
    out._12 = Up.x;
    out._13 = Direction.x;
    out._14 = 0.0f;

    out._21 = Right.y;
    out._22 = Up.y;
    out._23 = Direction.y;
    out._24 = 0.0f;

    out._31 = Right.z;
    out._32 = Up.z;
    out._33 = Direction.z;
    out._34 = 0.0f;

    out._41 = -Pos.x;
    out._42 = -Pos.y;
    out._43 = -Pos.z;
    out._44 = 1.0f;

    return out;
}

mdMat ViewMatrixLH(mdVec3 Pos,
               mdVec3 Front,
               mdVec3 Up)
{
    mdVec3 Direction = Vec3Norm(Front);
    mdVec3 Right = Vec3Norm(VecCross(Up, Direction));
    Up = Vec3Norm(VecCross(Direction, Right));

    mdMat out;

    out._11 = Right.x;
    out._12 = Up.x;
    out._13 = Direction.x;
    out._14 = 0.0f;

    out._21 = Right.y;
    out._22 = Up.y;
    out._23 = Direction.y;
    out._24 = 0.0f;

    out._31 = Right.z;
    out._32 = Up.z;
    out._33 = Direction.z;
    out._34 = 0.0f;

    out._41 = -Pos.x;
    out._42 = -Pos.y;
    out._43 = -Pos.z;
    out._44 = 1.0f;

    return out;
}

mdMat PerspcetiveMatrixRH(float fov, float aspect, float n, float f)
{
    float cot = cos(fov / 2.0f) / sin(fov / 2.0f);
    mdMat out;
    out._11 = cot / aspect;
    out._12 = 0.0f;
    out._13 = 0.0f;
    out._14 = 0.0f;

    out._21 = 0.0f;
    out._22 = cot;
    out._23 = 0.0f;
    out._24 = 0.0f;

    out._31 = 0.0f;
    out._32 = 0.0f;
    out._33 = -(f + n) / (f - n);
    out._34 = -1.0f;

    out._41 = 0.0f;
    out._42 = 0.0f;
    out._43 = -2 * f * n / (f - n);
    out._44 = 0.0f;

    return out;
}   

mdMat PerspcetiveMatrixLH(float fov, float aspect, float n, float f)
{
    float cot = cos(fov / 2.0f) / sin(fov / 2.0f);
    mdMat out;
    out._11 = cot / aspect;
    out._12 = 0.0f;
    out._13 = 0.0f;
    out._14 = 0.0f;

    out._21 = 0.0f;
    out._22 = cot;
    out._23 = 0.0f;
    out._24 = 0.0f;

    out._31 = 0.0f;
    out._32 = 0.0f;
    out._33 = f / (f - n);
    out._34 = 1.0f;

    out._41 = 0.0f;
    out._42 = 0.0f;
    out._43 = -f * n / (f - n);
    out._44 = 0.0f;

    return out;
}  