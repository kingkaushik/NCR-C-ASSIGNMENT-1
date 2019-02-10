#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
void btoh(char *, char *);
void htob(char *, char *);
int main()
{
	char binary[33], hexadecimal[9];
	printf("ENTER BINARY REPRESENTATION TO CONVERT IT INTO HEXADECIMAL->");
	scanf_s("%s", binary, 33);
	btoh(binary, hexadecimal);
	printf("\nHEXADECIMAL REPRESENTATION OF BINARY %s = %s", binary, hexadecimal);
	printf("\nENTER HEXADECIMAL (**WITHOUT 0X**) REPRESENTAION TO CONVERT IT INTO BINARY->");
	scanf_s("%s", hexadecimal, 9);
	htob(hexadecimal, binary);
	printf("\nBINARY  REPRESENTATION OF HEXADECIMAL %s = %s", hexadecimal, binary);
	_getch();
	return 0;
}
void btoh(char *binary, char *hexadecimal)
{
	int binary_length = strlen(binary);
	int remainder = binary_length % 4;
	int binary_length_replica = binary_length - 1;
	int partial_decimal = 0, flag = 0;
	if (remainder)
	{
		flag = 1;
		int power = remainder - 1;
		for (int i = 0; i < remainder; i++)
		{
			partial_decimal += ((binary[i] - 48) * (int)pow(2, power));
			power--;
		}
		switch (partial_decimal)
		{
		case 10:
			hexadecimal[0] = 'A';
			break;
		case 11:
			hexadecimal[0] = 'B';
			break;
		case 12:
			hexadecimal[0] = 'C';
			break;
		case 13:
			hexadecimal[0] = 'D';
			break;
		case 14:
			hexadecimal[0] = 'E';
			break;
		case 15:
			hexadecimal[0] = 'F';
			break;
		default:
			hexadecimal[0] = partial_decimal + 48;
			break;
		}
	}
	int k = remainder == 0 ? 0 : 1, count = 3;
	for (int bit_row = remainder; bit_row < binary_length; bit_row += 4)
	{
		partial_decimal = 0;
		count = 3;
		for (int bit_column = bit_row; bit_column < bit_row + 4; bit_column++)
		{
			partial_decimal += ((binary[bit_column] - 48) * (int)pow(2, count));
			count--;
		}
		switch (partial_decimal)
		{
		case 10:
			hexadecimal[k] = 'A';
			break;
		case 11:
			hexadecimal[k] = 'B';
			break;
		case 12:
			hexadecimal[k] = 'C';
			break;
		case 13:
			hexadecimal[k] = 'D';
			break;
		case 14:
			hexadecimal[k] = 'E';
			break;
		case 15:
			hexadecimal[k] = 'F';
			break;
		default:
			hexadecimal[k] = partial_decimal + 48;
			break;
		}
		k++;
	}
	hexadecimal[k] = '\0';
}

void htob(char *hexadecimal, char *binary)
{
	int hexadecimal_length = strlen(hexadecimal);
	int binary_ptr = 0;
	for (int i = 0; i < hexadecimal_length; i++)
	{
		int decimal = 0, flag = 0;
		if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F')
			decimal = hexadecimal[i] - 65 + 10;
		else if (hexadecimal[i] >= 'a' && hexadecimal[i] <= 'f')
			decimal = hexadecimal[i] - 'a' + 10;
		else
			decimal = hexadecimal[i] - 48;
		int decimal_replica = decimal;
		int k = 0;
		char binary_rev[32];
		while (decimal_replica)
		{
			int remainder = decimal_replica % 2;
			if (remainder == 1)
				binary_rev[k] = '1';
			else
				binary_rev[k] = '0';
			decimal_replica /= 2;
			k++;
		}
		binary_rev[k] = '\0';
		_strrev(binary_rev);
		int binary_rev_length = strlen(binary_rev);
		int m = k;
		if (i != 0)
		{
			for (int x = 0; x < 4 - binary_rev_length; x++)
			{
				binary_rev[m] = '0';
				m++;
				flag = 1;
			}
		}
		binary_rev[m] = '\0';
		if (flag == 1)
			_strrev(binary_rev);
		for (int f = 0; f < strlen(binary_rev); f++)
			binary[binary_ptr++] = binary_rev[f];
	}
	binary[binary_ptr] = '\0';
}