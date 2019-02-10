#include<stdio.h>
#include<conio.h>
void deletes2(char[], char[]);
int main()
{
	char s1[30], s2[30];
	printf("ENTER STRING1:");
	gets_s(s1,30);
	printf("\nENTER STRING2 TO FIND ALL THE CHARACTERS IN STRING1 WHICH ARE PRESENT IN STRING2 AND DELETE THEM\n:");
	gets_s(s2, 30);
	deletes2(s1, s2);
	printf("\nTHE STRING AFTER DELETE ALL CHARACTERS IN %s IS %s",s2,s1);
	_getch();
	return 0;
}
void deletes2(char s1[], char s2[])
{
	int s2_char[256],s3[30];
	for (int i = 0; s2[i]; i++)
	{
		s2_char[i] = 0;
	}
	for (int i = 0; s2[i]; i++)
	{
		s2_char[s2[i]] = 1;
	}
	int j = 0;
	for (int i = 0; s1[i]; i++ , j++)
	{
		if (s2_char[s1[i]] != 1)
		{
			s3[j] = s1[i];
		}
		else
		{
			j--;
		}
	}
	s3[j] = '\0';
	for (int i = 0; i < s3[i]; i++)
	{
		s1[i] = s3[i];
	}
	s1[j] = '\0';
}