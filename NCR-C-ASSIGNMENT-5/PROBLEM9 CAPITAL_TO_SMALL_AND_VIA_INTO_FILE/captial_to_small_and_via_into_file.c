#include<stdio.h>
#include<conio.h>

int main()
{
	char ch='\0';
	FILE *fptr = NULL;
	fopen_s(&fptr, "capital_small_conversions.txt", "w");
	printf("ENTER STRING AND PRESS ENTER TO END THE INPUT\n");
	if (fptr != NULL)
	{
		while (ch != '\n')
		{
			scanf_s("%c", &ch);
			if (ch >= 'a' && ch <= 'z')
			{
				fputc(ch - 32, fptr);
			}
			else if (ch >= 'A' && ch <= 'Z')
			{
				fputc(ch + 32, fptr);
			}
			else if (ch != EOF)
			{
				fputc(ch, fptr);
			}
		}
		printf("SUCCESSFULLY WRITTEN INTO FILE!");
	}
	else
	{
		printf("ERROR OCCURED!");
	}
	_getch();
	return 0;
}