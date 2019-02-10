#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
void itob(int, char *);
void btoi(char *);
int main()
{
	int decimal = -1;
	char binary[33];
	printf("ENTER THE NUMBER TO FIND IT'S BINARY REPRESENTAION->");
	scanf_s("%d", &decimal);
	itob(decimal, binary);
	printf("ENTER THE BINARY REPRESENTATION TO CONVERT IT TO DECIMAL->");
	scanf_s("%s",binary,33);
	btoi(binary);
	_getch();
	return 0;
}
void itob(int decimal, char *binary)
{
	int decimal_replica = decimal;
	int i = 0;
	char binary_rev[32];
	while (decimal_replica)
	{
		int remainder = decimal_replica % 2;
		if (remainder == 1)
			binary_rev[i] = '1';
		else
			binary_rev[i] = '0';
		decimal_replica /= 2;
		i++;
	}
	binary_rev[i] = '\0';
	int iterator = 0;
	for (int j = i - 1; j >= 0; j--)
	{
		binary[iterator] = binary_rev[j];
		iterator++;
	}
	binary[iterator] = '\0';
	printf("\nTHE BINARY REPRESENTATION OF %d = %s\n", decimal, binary);
}
void btoi(char binary[])
{
	int binary_length = strlen(binary);
	int decimal = 0,count=0;
	for (int bit = binary_length - 1; bit >= 0; bit--)
	{
		decimal += ((binary[bit] - 48) *(int) pow(2,count));
		count++;
	}
	printf("\nTHE DECIMAL REPRESENTATION OF %s = %d\n",binary,decimal);
}