#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct s1
{
	int a;
	char b;
};

union  u1
{
	int a;
	char b;
};

int main()
{
	struct s1 s;
	union u1 u;
	printf("SIZE OF STRUCTURE WITH INT AND CHAR IS %d", sizeof(s));
	printf("\nSIZE OF UNION WITH INT AND CHAR IS %d", sizeof(u));
	_getch();
	return 0;
}