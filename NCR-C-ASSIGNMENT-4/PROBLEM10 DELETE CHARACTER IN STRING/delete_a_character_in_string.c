#include<stdio.h>
#include<conio.h>
void delete(char[],char);
int main()
{
	char s1[30];
	char c;
	printf("ENTER A STRING MAX LENGTH OF 30 CHARACTERS:");
	gets_s(s1, 30);
	printf("\nENTER CHARACTER U WANT TO DELETE IN %s:",s1);
	c = getchar();
	delete(s1,c);
	printf("\nNOW THE STRING AFTER DELETING %c IS %s",c,s1);
	_getch();
	return 0;
}
void delete(char s1[], char c)
{
	char s2[30];
	int i = 0, j = 0, k = 0;
	for (; s1[i]; i++)
	{
		if (s1[i] != c)
			s2[k++] = s1[i];
		else
			j++;
	}
	s2[i - j] = '\0';
	for (i = 0; s2[i]; i++)
	{
		s1[i] = s2[i];
	}
	s1[i] = '\0';
}