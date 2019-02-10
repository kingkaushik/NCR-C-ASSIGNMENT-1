#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char ch[10];
	printf("ENTER STRING UPTO 9 CHARACTERS:");
	gets_s(ch,10);
	int input_length = strlen(ch);
	for (int i = 0; i < input_length; i++)
	{
		if (ch[i] >= 'a'&&ch[i] <= 'z')
		{
			ch[i] -= 32;
		}
		else if (ch[i] >= 'A'&&ch[i] <= 'Z')
		{
			ch[i] += 32;
		}
	}
	printf("\nTHE CHANGED STRING IS %s",ch);
	_getch();
	return 0;
}