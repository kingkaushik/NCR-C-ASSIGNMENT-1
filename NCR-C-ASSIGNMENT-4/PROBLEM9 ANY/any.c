#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char str1[80], str2[30];
	printf("ENTER STRING1 MAX LENGTH OF 79 CHARACTERS:");
	gets_s(str1, 80);
	printf("\nENTER STRING2 TO FIND IT'S FIRST OCCURANCE IN STRING1 MAX LENGTH 29 CHARACTERS:\n");
	gets_s(str2, 30);
	int first_occurance_position = any(str1,str2);
	printf("\nPOSITION OF FIRST OCCURANCE OF %s IN %s is %d", str1, str2, first_occurance_position);
	_getch();
	return 0;
}
int any(char str1[80], char str2[30])
{
	int str1_length = strlen(str1);
	int str2_length = strlen(str2);
	int i = 0, flag = 0, j = 0, k = 0;
	while (str2_length <= str1_length)
	{
		for (; i < str2_length; i++ , j++)
		{
			if (str1[j] == '\0')
			{
				flag = 1;
				break;
			}
			if (str1[j] != str2[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			return k+1;
		}
		flag = 0;
		i = 0;
		j = ++k;
	}
	return -1;
}