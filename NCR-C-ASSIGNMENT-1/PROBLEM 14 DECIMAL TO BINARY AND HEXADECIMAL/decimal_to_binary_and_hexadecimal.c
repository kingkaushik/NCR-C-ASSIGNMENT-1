#include<stdio.h>
#include<conio.h>
#include<string.h>
void itob(int, char *);
void itoh(int,char *);
int main()
{
	int decimal = -1;
	char binary[32],hexadecimal[32];
	printf("ENTER THE NUMBER TO FIND IT'S BINARY AND HEXADECIMAL REPRESENTAION->");
	scanf_s("%d",&decimal);
	itob(decimal,binary);
	itoh(decimal,hexadecimal);
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
	printf("\nTHE BINARY REPRESENTATION OF %d = %s\n",decimal,binary);
}
void itoh(int decimal, char *hexadecimal)
{
	int decimal_replica = decimal;
	int i = 0;
	char hexadecimal_rev[32];
	while (decimal_replica)
	{
		int remainder = decimal_replica % 16;
		if (remainder >= 0 && remainder <= 9)
			hexadecimal_rev[i] = remainder + 48;
		else
			hexadecimal_rev[i] = remainder + 55;
		decimal_replica /= 16;
		i++;
	}
	hexadecimal_rev[i] = '\0';
	int iterator = 0;
	for (int j = i - 1; j >= 0; j--)
	{
		hexadecimal[iterator] =hexadecimal_rev[j];
		iterator++;
	}
	hexadecimal[iterator] = '\0';
	printf("\nTHE HEXADECIMAL REPRESENTATION OF %d = 0X%s\n", decimal, hexadecimal);
}