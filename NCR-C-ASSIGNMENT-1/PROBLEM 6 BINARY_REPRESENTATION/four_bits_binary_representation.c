#include<stdio.h>
#include<conio.h>
int main()
{
	int number = -1;
	char binary[5];
	printf("ENTER THE NUMBER BETWEEN 0 AND 32 EXCLUSIVE:");
	scanf_s("%d",&number);
	if (number >= 0 && number < 32)
	{
		int number_replica = number;
		int remainder = -1;
		int iterator = 3;
		while (number_replica)
		{
			remainder = number_replica % 2;
			binary[iterator] = remainder+48;
			number_replica /= 2;
			iterator--;
		}
		binary[4] = '\0';
		for (int it = iterator+1; it <= 3; it++)
		{
			printf("%c",binary[it]);
		}
		printf("\n");
	}
	else
		printf("%d is not between RANGE [0,32) ",number);
	_getch();
	return 0;
}