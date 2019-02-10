#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int replace(char *cat)
{
	int cat_length = strlen(cat),no_of_spaces=0;
	for (int i = 0; i < cat_length; i++)
	{
		if (*(cat + i) == ' ')
		{
			*(cat + i) = '-';
			no_of_spaces++;
		}
	}
	return no_of_spaces;
}
int main()
{
	int length_of_string = strlen("The cat sat");
	char *cat = (char *)calloc(length_of_string, sizeof(char));
	char str[] = "The cat sat";
	int i = 0;
	for (; i < length_of_string; i++)
	{
		*(cat + i) = str[i];
	}
	*(cat + i) = '\0';
	int n = replace(cat);
	printf("THE STRING IN CAT = %s\n",cat);
	printf("THE NO OF SPACES WERE %d",n);
	_getch();
	return 0;
}