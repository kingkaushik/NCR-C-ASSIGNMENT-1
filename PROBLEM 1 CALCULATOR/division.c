#include<stdio.h>
extern int operand1, operand2;
void division()
{
	if (operand2 != 0)
	{
		int quotient = operand1 / operand2;
		printf("%d / %d = %d\n", operand1, operand2, quotient);
	}
	else
	{
		printf("division by zero is not defined\n");
	}
}