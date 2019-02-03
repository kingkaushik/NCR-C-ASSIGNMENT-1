#include<stdio.h>
#include<conio.h>
int main()
{
	int number = -1,number_replica=-1;
	int reversed_number = 0,remainder=-1;
	printf("ENTER THE NUMBER TO CHECK IF IT'S A PALINDROME:");
	scanf_s("%d",&number);
	number_replica = number;
	while (number_replica)
	{
		remainder = number_replica % 10;
		reversed_number = reversed_number * 10 + remainder;
		number_replica /= 10;
	}
	if (reversed_number == number)
		printf("\n%d is a palindrome", number);
	else
		printf("\n%d is not a palindrome",number);
	_getch();
	return 0;
}