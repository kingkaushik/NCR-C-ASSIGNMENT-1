#include<stdio.h>
#include<conio.h>
int main()
{
	int number = -1,sum_of_digits_of_number=0;
	printf("ENTER THE POSITIVE NUMBER TO FIND SUM OF IT'S DIGITS:");
	scanf_s("%d",&number);
	int number_replica = number;
	int remainder = -1;
	while (number_replica>0)
	{
		remainder = number_replica % 10;
		sum_of_digits_of_number += remainder;
		number_replica /= 10;
	}
	if (number >= 0)
		printf("THE SUM OF DIGITS OF %d IS %d", number, sum_of_digits_of_number);
	else
		printf("%d IS NOT A POSITIVE NUMBER",number);
	_getch();
	return 0;
}