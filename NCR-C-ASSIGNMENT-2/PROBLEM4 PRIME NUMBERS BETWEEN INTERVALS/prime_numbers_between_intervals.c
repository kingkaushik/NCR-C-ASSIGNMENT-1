#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int start_of_range=-1, end_of_range = -1;
	printf("ENTER THE RANGE TO FIND PRIME NUMBERS BETWEEN THE RANGE\n");
	printf("ENTER START OF THE RANGE->");
	scanf_s("%d",&start_of_range);
	printf("\nENTER THE END OF THE RANGE->");
	scanf_s("%d",&end_of_range);
	int *prime_numbers_in_the_given_range = (int *)calloc(end_of_range,sizeof(int));
	for (int outer_iterator = 2; outer_iterator <= (int)sqrt(end_of_range); outer_iterator++)
	{
		for (int inner_iterator = 2; inner_iterator*outer_iterator <= end_of_range; inner_iterator++)
		{
			int product = inner_iterator * outer_iterator;
			if (outer_iterator == 2)
			{
				*(prime_numbers_in_the_given_range + product) = -1;
			}
			else
			{
				if (*(prime_numbers_in_the_given_range + outer_iterator) == -1)
				{
					continue;
				}
				else
				{
					*(prime_numbers_in_the_given_range + product) = -1;
				}
			}
		}
	}
	printf("PRIME NUMBER BETWEEN %d AND %d IS/ARE\n",start_of_range,end_of_range);
	for (int iterator = start_of_range; iterator <= end_of_range; iterator++)
	{
		int prime_flag = *(prime_numbers_in_the_given_range + iterator);
		if (prime_flag != -1)
		{
			printf("%d\n",iterator);
		}
	}
	_getch();
	return 0;
}