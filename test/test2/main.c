#include <stdio.h>
#include <MD_Math.h>

void PrintVec3(const char* text, mdVec3 v)
{
    printf(text); printf("\n");
    printf("%f\n", v.x);
    printf("%f\n", v.y);
    printf("%f\n", v.z);
}

int main()
{
    mdVec3 result;
    mdVec3 v1 = {1.0f, 0.0f, 0.0f};
    mdVec3 v2 = {0.0f, 1.0f, 0.0f};

    result = VecCross(v1, v2);

    PrintVec3("v1", v1);
    PrintVec3("v2", v2);
    printf("v1 x v2\n");
    PrintVec3("result", result);
    return 0;
}