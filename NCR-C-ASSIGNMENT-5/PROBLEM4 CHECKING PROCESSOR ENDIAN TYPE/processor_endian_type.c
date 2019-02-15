#include<stdio.h>
#include<conio.h>
int main()
{
	unsigned int number = 1;
	char *ch = (char *)&number;
	if (*ch)
	{
		printf("THE PROCESS IS LITTLE ENDIAN");
	}
	else
	{
		printf("THE PROCESSOR IS BIG ENDIAN");
	}
	_getch();
	return 0;
}