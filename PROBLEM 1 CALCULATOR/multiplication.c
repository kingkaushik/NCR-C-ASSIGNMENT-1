#include<stdio.h>
extern int operand1, operand2;
void multiplication()
{
	int product = operand1 * operand2;
	printf("%d * %d = %d\n", operand1, operand2, product);
}