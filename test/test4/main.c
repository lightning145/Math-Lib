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
    mdQuat q = {0.0f, 0.0f, 0.0f, 0.0f};
    PrintQuat("q", q);
    return 0;
}