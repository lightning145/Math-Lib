#include <MD_Math.h>
#include <Constant.h>
#include <stdio.h>

void PrintQuat(const char* text, mdQuat q)
{
    printf(text); printf("\n");
    printf("%f, %f, %f, %f\n", q.a, q.b, q.c, q.d);
    printf("\n");
}

int main()
{
    mdQuat q1 = {1.0f, 2.0f, 3.0f, 4.0f};
    mdQuat q2 = {2.0f, 3.0f, 5.0f, 2.0f};
    PrintQuat("q1 * q2", QuatDot(q1, q2));
    printf("q1 * q2 Length %f\n", QuatLength(QuatDot(q1, q2)));
    PrintQuat("q1 * q2 Norm", QuatNorm(QuatDot(q1, q2)));
    printf("q1 * q2 Norm Length %f\n", QuatLength(QuatNorm(QuatDot(q1, q2))));
    PrintQuat("q1 Inverse", QuatInv(q1));
    mdVec3 v = {1.0f, 0.0f, 0.0f};
    mdVec3 Axis = {0.0f, 0.0f, 1.0f};
    mdQuat qq = QuatFromAxisAngle(Axis, MD_PI_2);
    v = RotateVec(qq, v);
    printf("rotate"); printf("\n");
    printf("%f\n", v.x);
    printf("%f\n", v.y);
    printf("%f\n", v.z);

    PrintQuat("q1 -> q2 t = 0.5", QuatSlerp(q1, q2, 0.5));

    return 0;
}