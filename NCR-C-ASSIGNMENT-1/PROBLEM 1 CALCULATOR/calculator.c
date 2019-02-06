#include<stdio.h>
#include<conio.h>
void addition();
void subtraction();
void multiplication();
void division();
int operand1,operand2;
int main()
{
    printf("ENTER TWO NUMBERS FOR PERFORMING BASIC ARITHMETIC OPERATIONS\n");
    printf("ENTER FIRST INTEGER OPERAND = ");
    scanf_s("%d",&operand1);
    printf("ENTER SECOND INTEGER OPERAND = ");
    scanf_s("%d",&operand2);
    addition();
    subtraction();
    multiplication();
    division();
	_getch();
    return 0;
}