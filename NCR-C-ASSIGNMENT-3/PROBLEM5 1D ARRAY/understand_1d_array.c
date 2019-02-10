#include<stdio.h>
#include<conio.h>
int main()
{
	int x[8] = { 10,20,30,40,50,60,70,80 };	printf("&x[0] i.e address of first element of x = %u", x);	printf("\n&x[2] i.e address of third element of x = %u", x+3);	printf("\nx[0] i.e value of first element of x = %d", *x);	printf("\nx[0]+2 i.e value of first element of x plus 2 = %d", *x + 2);	printf("\nx[2] i.e value of third element of x = %d", *(x + 2));	_getch();
	return 0;
}