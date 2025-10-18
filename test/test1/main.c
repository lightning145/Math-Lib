#include <stdio.h>
#include <MD_Math.h>
#include <Constant.h>

int main()
{
    printf("Factorial(3): \n");
    printf("%d\n", MD_Factorial(3));
    printf("\n");

    printf("Abs(-2.0f): \n");
    printf("%f\n", MD_Abs(-2.0f));
    printf("\n");

    printf("Rsqrt(2.0f): \n");
    printf("%f\n", MD_Rsqrt(2.0f));
    printf("\n");
    
    printf("Log2(2.0f): \n");
    printf("%f\n", MD_Log2(2.0f));
    printf("\n");

    printf("Max(2.0f, 3.0f): \n");
    printf("%f\n" , MD_Max(2.0f, 3.0f) );
    printf("\n");

    printf("Min(2.0f, 3.0f): \n");
    printf("%f\n" , MD_Min(2.0f, 3.0f) );
    printf("\n");
    
    printf("Hypot(4.0f, 3.0f): \n");
    printf("%f\n" , MD_Hypot(4.0f, 3.0f) );
    printf("\n");
    
    printf("Cbrt(27.0f): \n");
    printf("%f\n" , MD_Cbrt(27.0f) );
    printf("\n");
    
    printf("Expml(1.0f): \n");
    printf("%f\n" , MD_Expml(1.0f) );
    printf("\n");
    
    printf("Lnlp(2.0f): \n");
    printf("%f\n" , MD_Lnlp(2.0f) );
    printf("\n");

    printf("Tan(PI_4): \n");
    printf("%f\n" , MD_Tan(MD_PI_4) );
    printf("\n");
    
    printf("ArSinh(0.5f): \n");
    printf("%f\n" , MD_ArSinh(0.5f) );
    printf("\n");
    
    printf("ArCosh(5.0f): \n");
    printf("%f\n" , MD_ArCosh(5.0f) );
    printf("\n");
    
    printf("ArTanh(0.5f): \n");
    printf("%f\n" , MD_ArTanh(0.5f) );
    printf("\n");
    
    printf("Trunc(2.23f): \n");
    printf("%d\n" , MD_Trunc(2.23f) );
    printf("\n");
    
    printf("Round(2.6f): \n");
    printf("%d\n" , MD_Round(2.6f) );
    printf("\n");

    printf("Equal(2.0f, 2.00000001f): \n");
    printf("Bool Value: %d\n" , MD_Equal(2.0f, 2.000000001f) );
    printf("\n");
    
    printf("Sin(ToRadian(30.0f)): \n");
    printf("%f\n" , sin(MD_ToRadian(30.0f)) );
    printf("\n");
    
    printf("ToAngle(MDM_PI_2): \n");
    printf("%f\n" , MD_ToAngle(MD_PI_2) );
    printf("\n");
   
    return 0;
}