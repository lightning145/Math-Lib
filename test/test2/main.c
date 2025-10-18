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
    mdVec3 v1 = {1.0f, 2.0f, 0.0f};
    mdVec3 v2 = {0.0f, 1.0f, 0.0f};

    //result = Vec3Mix(v1, v2, 0.5f);
    result = ProjVec3(v1, v2);

    PrintVec3("v1", v1);
    PrintVec3("v2", v2);
    printf("v1 x v2\n");
    PrintVec3("result", result);

    printf("\n %f \n", ProjOfVec3(v1, v2));
    return 0;
}