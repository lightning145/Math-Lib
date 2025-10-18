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

void PrintMat(const char* text, mdMat m)
{
    printf(text); printf("\n");
    printf("%f, %f, %f, %f\n", m.coords[0], m.coords[1], m.coords[2], m.coords[3]);
    printf("%f, %f, %f, %f\n", m.coords[4], m.coords[5], m.coords[6], m.coords[7]);
    printf("%f, %f, %f, %f\n", m.coords[8], m.coords[9], m.coords[10], m.coords[11]);
    printf("%f, %f, %f, %f\n", m.coords[12], m.coords[13], m.coords[14], m.coords[15]);
    printf("\n");
}

int main()
{
    mdMat m = {
        1.0f, 2.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };

    PrintMat("Idnetity", m);
    return 0;
}