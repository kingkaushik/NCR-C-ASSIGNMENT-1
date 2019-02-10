#include<stdio.h>
#include<conio.h>
int main()
{
	int number=-1;
	printf("ENTER NUMBER BETWEEN 0 AND 255:");
	scanf_s("%d", &number);
	if (number >= 0 && number <= 255)
	{
		int set_bit_count = 0;
		int number_replica = number;
		int remainder = -1;
		while (number_replica)
		{
			remainder = number_replica % 2;
			if (remainder == 1)
			{
				set_bit_count++;
			}
			number_replica /= 2;
		}
		printf("\nSET BIT COUNT OF %d IS %d", number, set_bit_count);
	}
	else
	{
		printf("\nINVALID INPUT");
	}
	_getch();
	return 0;
}