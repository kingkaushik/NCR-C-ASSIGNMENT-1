#include<stdio.h>
#include<conio.h>
#include<string.h>
void reverse(char str[],int start_position,int end_position)
{
	if (start_position > end_position)
		return;
	char temp = str[start_position];
	str[start_position] = str[end_position];
	str[end_position] = temp;
	reverse(str, start_position + 1, end_position - 1);
}
int main()
{
	char str[10];
	printf("ENTER THE STRING:");
	scanf_s("%s",str,10);
	int str_length = strnlen_s(str,10);
	reverse(str,0,str_length-1);
	printf("%s",str);
	_getch();
	return 0;
}