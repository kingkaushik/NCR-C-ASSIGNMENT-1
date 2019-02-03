#include<stdio.h>
#include<conio.h>
int main()
{
	int maximum_number_of_pattern = -1;
	printf("ENTER THE MAXIMUM NUMBER OF PATTERN:");
	scanf_s("%d",&maximum_number_of_pattern);
	for (int pattern_row = 1; pattern_row <= maximum_number_of_pattern; pattern_row++)
	{
		for (int pattern_column = maximum_number_of_pattern; pattern_column >= 1; pattern_column--)
		{
			if (pattern_column <= pattern_row)
			{
				printf("%d ",pattern_column);
			}
			else
			{
				printf("  ");
			}
		}
		for (int pattern_column = 2; pattern_column <= pattern_row; pattern_column++)
		{
			printf("%d ",pattern_column);
		}
		printf("\n");
	}
	_getch();
	return 0;
}