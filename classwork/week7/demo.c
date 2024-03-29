#include <stdio.h>

float InputDouble();
float SumDouble(float x, float y);
void PrintOut(float x);

int main()
{
    float a1, a2, sumVal;
    a1 = InputDouble(); // function calling
    fflush(stdin);
    a2 = InputDouble();         // function calling
    sumVal = SumDouble(a1, a2); // function calling
    PrintOut(sumVal);           // function calling
    return 0;
}

float InputDouble()
{
    float x;
    printf("\nInput real value : ");
    scanf("%f", &x);
    return x;
}

float SumDouble(float x, float y)
{
    return x + y;
}

void PrintOut(float x)
{
    printf("\n Result of sum is : %.2f", x);
}