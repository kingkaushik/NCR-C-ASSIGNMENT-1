#include<stdio.h>
#include<conio.h>

int main()
{
	int ch;
	FILE *fptr = NULL;
	fopen_s(&fptr, "printing_same_file_onto_console.c", "r+");
	if (fptr != NULL)
	{
		while (!feof(fptr))
		{
			char ch = fgetc(fptr);
			if (ch != EOF)
			{
				printf("%c", ch);
			}
		}
		fclose(fptr);
	}
	else
	{
		printf("ERROR");
	}
	_getch();
	return 0;
}