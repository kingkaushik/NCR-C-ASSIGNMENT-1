#include<stdio.h>
#include<conio.h>
#include<string.h>
int main() {
	int i, j, count;
	char str[25][25], temp[25];
	printf("How many strings u are going to enter?: ");
	scanf_s("%d", &count);
	printf("\nEnter Strings one by one: \n");
	for (i = 0; i < count; i++)
	{
		printf("Enter String %d:",i+1);
		scanf_s("%s",str[i], 25);
	}
	for (i = 0; i <= count; i++)
		for (j = i + 1; j <= count; j++) {
			if (strcmp(str[i], str[j]) > 0) {
				strcpy_s(temp,25, str[i]);
				strcpy_s(str[i],25, str[j]);
				strcpy_s(str[j],25, temp);
			}
		}
	printf("Order of Sorted Strings:\n");
	for (i = 0; i < count; i++)
		puts(str[i]);
	_getch();
	return 0;
}