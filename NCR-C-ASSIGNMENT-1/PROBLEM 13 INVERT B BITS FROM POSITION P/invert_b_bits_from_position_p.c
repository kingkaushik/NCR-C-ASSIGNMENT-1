#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void invertponwards(int, int, int);

int main()
{
	int number = -1, position = -1, no_of_bits_to_be_rotated = -1;
	printf("ENTER THE NUMBER:");
	scanf_s("%d", &number);
	printf("\nENTER THE POSITION:");
	scanf_s("%d", &position);
	printf("\nENTER THE NO OF BITS:");
	scanf_s("%d", &no_of_bits_to_be_rotated);
	invertponwards(number,position,no_of_bits_to_be_rotated);
	_getch();
	return 0;
}
void invertponwards(int number,int position,int no_of_bits_to_be_rotated)
{
	char binary[33];
	_itoa_s(number, binary, 33, 2);
	int no_of_bits_of_binary = strlen(binary);
	if (no_of_bits_of_binary >= position)
	{
		if (position >= no_of_bits_to_be_rotated)
		{
			int start_pos = no_of_bits_of_binary - position;
			int end_pos = no_of_bits_of_binary - (position - no_of_bits_to_be_rotated) - 1;			
			char *bits_after_rotated;
			bits_after_rotated = (char *)malloc((position+1) * sizeof(char));
			int i = 0;
			for (int iterator=end_pos;iterator>=start_pos;iterator--)
			{
				*(bits_after_rotated+i) = binary[iterator];
				binary[iterator] = '0'; 
				i++;
			}
			for (int k=1; k <= no_of_bits_of_binary - no_of_bits_to_be_rotated - 1; k++,i++)
				*(bits_after_rotated + i) = '0';
			*(bits_after_rotated + i) = '\0';
			int rotated_bits_length = strlen(bits_after_rotated);
			int rotated_number = 0,binary_number_result=0;
			i = 0;
			for (int iterator = rotated_bits_length - 1; iterator >= 0; iterator--)
			{
				rotated_number += ((bits_after_rotated[iterator] - 48)*(int)pow(2,i));
				i++;
			}
			i = 0;
			for (int iterator = no_of_bits_of_binary-1; iterator >= 0; iterator--)
			{
				binary_number_result += ((binary[iterator] - 48)*(int)pow(2,i));
				i++;
			}
			int resultant_number = binary_number_result | rotated_number;
			printf("THE RESULTANT NUMBER = %d",resultant_number);
		}
		else
		{
			printf("\nCANNOT ROTATE %d NO OF BITS FROM %dth POSITION",no_of_bits_to_be_rotated,position);
		}
	}
	else
	{
		printf("\n NO OF BITS OF %d is %d . SO IT CANNOT HAVE POSITION %d",number,no_of_bits_of_binary,position);
	}
}