#include<stdio.h>
#include<conio.h>
int main()
{
	char *color[6] = { "red", "green", "blue", "white", "black", "yellow" };
	printf("THE ADDRESS OF 1ST CHARACTER OF FIRST WORD IS %u\n",color);
	printf("THE ADDRESS OF 1ST CHARACTER OF THIRD WORD IS %u\n", color+2);
	printf("THE VALUE OF FIRST WORD IS %s\n", *color);
	printf("THE VALUE OF THIRD WORD IS %s\n", *(color+2));
	printf("THE VALUE OF SIXTH WORD IS color[5] or *(color+5) %s=%s",color[5],*(color+5));
	_getch();
	return 0;
}