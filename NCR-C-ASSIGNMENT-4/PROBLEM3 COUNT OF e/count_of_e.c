#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char * s[] = {
"we will teach you how to",
"Move a mountain" ,
"Level a building",
"Erase the past" ,
"Make a million" };
	int count_of_e = 0;
	for (int i = 0; i <= 4; i++)
	{
		int slen = strlen(s[i]);
		for (int j = 0; j < slen; j++)
		{
			if (s[i][j] == 'e')
			{
				count_of_e++;
			}
		}
	}
	printf("THE COUNT OF E'S = %d\n",count_of_e);
	_getch();
	return 0;
}