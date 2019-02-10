#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void expand(char *, char *);
int str1_len = -1, str2_len = -1;
int main()
{
	char *str1, *str2;	
	printf("ENTER LENGTH OF THE STRING:");
	scanf_s("%d", &str1_len);
	str1 = (char *)calloc(str1_len, sizeof(char));
	str2 = (char *)calloc(str1_len, sizeof(char));
	printf("\nENTER STRING1:");
	scanf_s("%s",str1,str1_len);
	expand(str1, str2);
	printf("\n%s",str2);
	_getch();
	return 0;
}
void expand(char *str1, char *str2)
{
	str2_len = str1_len;
	int j = 0;
	for (int i = 0; str1[i]; i++)
	{
		if (*(str1 + i) == '-')
		{
			char a = *(str1 + i - 1);			
			char b = *(str1 + i + 1);			
			str2 = (char*)realloc(str2, j + b - a +1);
			for (char c = a + 1; c < b; c++)
			{				
				*(str2 + j) = c;				
				j++;
			}
		}
		else
		{
			*(str2 + j) = *(str1 + i);
			j++;
		}
	}
	*(str2 + j) = '\0';
}