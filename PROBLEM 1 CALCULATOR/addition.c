#include<stdio.h>
extern int operand1,operand2;
void addition()
{
    int sum = operand1 + operand2;
    printf("%d + %d = %d\n",operand1,operand2,sum);
}