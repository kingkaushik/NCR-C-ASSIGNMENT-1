#include<stdio.h>
#include<conio.h>
#include<math.h>
void rotate_right(int, int);
int main()
{
	int number = -1, positions_rotated_towards_right = -1;
	printf("ENTER NUMBER:");
	scanf_s("%d", &number);
	printf("ENTER NUMBER OF POSITIONS TO BE ROTATED TOWARDS RIGHT:");
	scanf_s("%d", &positions_rotated_towards_right);
	rotate_right(number, positions_rotated_towards_right);
	_getch();
	return 0;
}
void rotate_right(int number, int positions_rotated_towards_right)
{
	int no_of_digits_of_given_number = 0, number_replica = number, no_of_zeroes_in_given_number=0;
	while (number_replica)
	{
		int remainder = number_replica % 10;
		if (remainder == 0)
		{
			no_of_zeroes_in_given_number++;
		}
		no_of_digits_of_given_number++;
		number_replica /= 10;
	}
	int positions = positions_rotated_towards_right;
	number_replica = number;
	while (positions--)
	{
		int remainder = number_replica % 10;
		number_replica /= 10;
		if (remainder == 0)
		{
			no_of_digits_of_given_number--;
		}
		else
		{
			number_replica = (int)remainder*pow(10, no_of_digits_of_given_number-1) + number_replica;
		}
	}
	printf("THE NUMBER %d AFTER ROTATING FOR %d POSITIONS TOWARDS RIGHT BECOMES %d",number,positions_rotated_towards_right,number_replica);
}