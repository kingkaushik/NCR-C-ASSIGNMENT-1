#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void ones_equivalent(char *);
void btoh(char *, char *);
void htob(char *, char *);
int btoi(char *);
void itob(int, char*);
void masking(char*, int);
int main()
{
	char hexadecimal[9],binary[33];
	printf("ENTER HEXADECIMAL NUMBER (**WITHOUT 0X**) MAX OF 8 DIGITS:");
	scanf_s("%s", hexadecimal,9);
	printf("CHOOSE ONE OF THE BELOW\n");
	printf("1.Display the hexadecimal equivalent of the one's complement\n");
	printf("2.Carry out a masking operation and then display the hexadecimal equivalent of the result\n");
	printf("3.Carry out a bit shifting operation and then display the hexadecimal equivalent of	the result\n");
	printf("4.Exit\n");
	int choice;
	printf("\nENTER YOUR CHOICE:");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("\nONE'S EQUIVALENT OF %s HEXADECIMAL IS ",hexadecimal);
		htob(hexadecimal, binary);		
		ones_equivalent(binary);
		btoh(binary, hexadecimal);
		printf(" %s",hexadecimal);
		break;
	case 2:
		printf("\nPRESS 1:AND 2:OR 3:XOR");
		printf("\nENTER YOUR CHOICE:");
		scanf_s("%d", &choice);
		htob(hexadecimal, binary);
		if (choice<1 || choice>3)
		{
			printf("INVALID INPUT");
			break;
		}
		masking(binary, choice);
		btoh(binary, hexadecimal);
		char ch[4]="AND";
		if (choice == 2)
		{
			ch[0] = 'O';
			ch[1] = 'R';
			ch[2] = '\0';
		}
		if (choice == 3)
		{
			ch[0] = 'X';
			ch[1] = 'O';
			ch[2] = 'R';
			ch[3] = '\0';
		}
		printf("\nNOW THE HEXADECIMAL AFTER MASKING BY %s IS %s",ch,hexadecimal);
		break;
	case 3:
		printf("\nPRESS 1:LEFT SHIFT  2:RIGHT SHIFT");
		printf("\nENTER YOUR CHOICE:");
		scanf_s("%d", &choice);
		printf("\nENTER NO OF BITS TO BE SHIFTED:");
		int bits = -1;
		scanf_s("%d", &bits);
		htob(hexadecimal, binary);
		int decimal = btoi(binary);
		if (choice == 1)
			decimal = decimal << bits;
		else if(choice == 2)
		{
			decimal = decimal >> bits;
		}
		else
		{
			printf("\nINVALID INPUT");
			break;
		}
		itob(decimal,binary);
		btoh(binary,hexadecimal);
		printf("\nHEXADECIMAL VALUE NOW IS %s",hexadecimal);
		break;
	case 4:
		exit(0);
	default:
		printf("\nINVALID INPUT");
		break;
	}
	_getch();
	return 0;
}
int btoi(char binary[])
{
	int binary_length = strlen(binary);
	int decimal = 0, count = 0;
	for (int bit = binary_length - 1; bit >= 0; bit--)
	{
		decimal += ((binary[bit] - 48) *(int)pow(2, count));
		count++;
	}
	return decimal;
}
void masking(char *binary,int choice)
{
	int binary_length = strlen(binary);
	char *binary_mask = (char *)calloc(binary_length,sizeof(char));
	char ch = '1';
	if (choice == 1)
		ch = '0';
	for (int i = 0; i < binary_length; i++)
	{
		*(binary_mask + i) = ch;
	}
	*(binary_mask + binary_length) = '\0';
	for (int i = 0; i < binary_length; i++)
	{
		if (choice == 1)
		{
			int bit = (*(binary + i) - 48) & (*(binary_mask + i)-48);
			*(binary + i) = bit + 48;
		}
		else if(choice == 2)
		{
			int bit = (*(binary + i) - 48) || (*(binary_mask + i) - 48);
			*(binary + i) = bit + 48;
		}
		else
		{
			int bit = (*(binary + i) - 48) ^ (*(binary_mask + i) - 48);
			*(binary + i) = bit + 48;
		}
	}
	*(binary + binary_length) = '\0';
}
void ones_equivalent(char *binary)
{
	int binary_length = strlen(binary);
	for  (int i = 0; i < binary_length;  i++)
	{
		if (*(binary + i) == '0')
			*(binary + i) = '1';
		else
			*(binary + i) = '0';
	}
	*(binary + binary_length) = '\0';
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
}