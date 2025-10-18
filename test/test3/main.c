#include <stdio.h>
#include <MD_Math.h>

/*
void PrintMat(const char* text, mdMat m)
{
    printf(text); printf("\n");
    printf("%f, %f, %f, %f\n", m._11, m._12, m._13, m._14);
    printf("%f, %f, %f, %f\n", m._21, m._22, m._23, m._24);
    printf("%f, %f, %f, %f\n", m._31, m._32, m._33, m._34);
    printf("%f, %f, %f, %f\n", m._41, m._42, m._43, m._44);
    printf("\n");
}
*/

/*
void PrintMat(const char* text, mdMat m)
{
    printf(text); printf("\n");
    printf("%f, %f, %f, %f\n", m.coords[0], m.coords[1], m.coords[2], m.coords[3]);
    printf("%f, %f, %f, %f\n", m.coords[4], m.coords[5], m.coords[6], m.coords[7]);
    printf("%f, %f, %f, %f\n", m.coords[8], m.coords[9], m.coords[10], m.coords[11]);
    printf("%f, %f, %f, %f\n", m.coords[12], m.coords[13], m.coords[14], m.coords[15]);
    printf("\n");
}
*/

void PrintMat(const char* text, mdMat m)
{
    printf(text); printf("\n");
    printf("%f, %f, %f, %f\n", m.ij[0][0], m.ij[0][1], m.ij[0][2], m.ij[0][3]);
    printf("%f, %f, %f, %f\n", m.ij[1][0], m.ij[1][1], m.ij[1][2], m.ij[1][3]);
    printf("%f, %f, %f, %f\n", m.ij[2][0], m.ij[2][1], m.ij[2][2], m.ij[2][3]);
    printf("%f, %f, %f, %f\n", m.ij[3][0], m.ij[3][1], m.ij[3][2], m.ij[3][3]);
    printf("\n");
}

void PrintVec4(const char* text, mdVec4 v)
{
    printf(text); printf("\n");
    printf("%f, %f, %f, %f\n", v.x, v.y, v.z, v.w);
    printf("\n");
}

int main()
{
    mdMat m = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    mdMat m2 = {
        1.0f, 4.0f, 5.0f, 6.0f,
        2.0f, 6.0f, 3.0f, 5.0f,
        3.0f, 5.0f, 6.0f, 7.0f,
        2.0f, 5.0f, 6.0f, 3.0f
    };

    mdVec4 v = {1.0f, 2.0f, 3.0f, 4.0f};
    
    //PrintMat("Idnetity",MatMul(m , m2));
     PrintMat("",MatMul(InvMat(m2), m2));
    //printf("\n %f \n", DetMat(m2));
   //PrintVec4("" ,MulVec(IdentityMat(), v));
    return 0;
}