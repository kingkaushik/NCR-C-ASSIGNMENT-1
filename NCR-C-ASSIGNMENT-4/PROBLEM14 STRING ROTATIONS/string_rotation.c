#include<stdio.h>
#include<conio.h>
int main()
{
	char string[30],str2[30];
	printf("ROTAIONS OF A STRING\n");
	printf("ENTER THE STRING:");
	scanf_s("%s", string, 30);
	for (int i = 0; string[i]; i++)
	{
		int k = 0;
		for (int j = i; string[j]; j++)
		{
			str2[k] = string[j];
			k++;
		}
		for (int j = 0; j < i; j++)
		{
			str2[k++] = string[j];
		}
		str2[k] = '\0';
		printf("\nAFTER ROTATION %d : %s",i,str2);
	}
	_getch();
	return 0;
}