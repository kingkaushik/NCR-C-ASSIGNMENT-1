#include<stdio.h>
#include<conio.h>

#define fun(x) printf("%s","HELLO "##x)

int main()
{
#define x "sir"
#ifdef x
	fun(x);
#endif
	_getch();
	return 0;
}