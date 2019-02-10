#include<stdio.h>
#include<conio.h>
int main()
{
	int factorial = 1, number = -1;
	printf("ENTER THE NUMBER TO FIND IT'S FACTORIAL:");
	scanf_s("%d",&number);
	for  (int i = 2; i <=number;  i++)
	{
		factorial *= i;
	}
	printf("\nFACTORIAL OF %d = %d\n",number,factorial);
	_getch();
	return 0;
}