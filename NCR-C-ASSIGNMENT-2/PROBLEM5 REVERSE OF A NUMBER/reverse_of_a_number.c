#include<stdio.h>
#include<conio.h>
int main()
{
	int number = -1, number_replica = -1;
	int reversed_number = 0, remainder = -1;
	printf("ENTER THE NUMBER TO GET THE REVERSE OF IT:");
	scanf_s("%d", &number);
	number_replica = number;
	while (number_replica)
	{
		remainder = number_replica % 10;
		reversed_number = reversed_number * 10 + remainder;
		number_replica /= 10;
	}
	printf("THE REVERSE OF %d IS %d",number,reversed_number);
	_getch();
	return 0;
}