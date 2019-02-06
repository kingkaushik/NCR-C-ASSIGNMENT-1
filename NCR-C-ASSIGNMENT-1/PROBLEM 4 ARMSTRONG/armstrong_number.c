#include<stdio.h>
#include<conio.h>

int is_armstrong(int);
int find_cube(int);

int main()
{
	int number = -1;
	printf("ENTER THE NUMBER TO CHECK IF IT'S AN ARMSTRONG NUMBER:");
	scanf_s("%d", &number);
	if (is_armstrong(number))
		printf("%d is an armstrong number", number);
	else
		printf("%d is not an armstrong number",number);
	_getch();
	return 0;
}

int is_armstrong(int number)
{
	int remainder = -1;
	int sum = 0;
	int number_replica = number;
	while (number_replica)
	{
		remainder = number_replica % 10;
		sum += find_cube(remainder);
		number_replica /= 10;
	}
	if (sum == number)
		return 1;
	return 0;
}

int find_cube(int number)
{
	int cube_of_number = number * number*number;
	return cube_of_number;
}