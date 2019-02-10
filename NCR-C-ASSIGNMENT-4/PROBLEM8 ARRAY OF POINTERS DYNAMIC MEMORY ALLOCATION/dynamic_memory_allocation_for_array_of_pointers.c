#include<stdio.h>
#include<conio.h>
int main()
{
	char *array_of_pointer[30];
	int no_of_strings = -1;
	printf("ENTER NUMBER OF STRINGS:");
	scanf_s("%d",&no_of_strings);
	for(int i=0;i<no_of_strings;i++)
		array_of_pointer[i] =(char*) calloc(sizeof(char*),30); 
	printf("\nENTER %d STRING LESS THAN 30 LENGTH",no_of_strings);
	for (int i = 0; i < no_of_strings; i++)
	{
		printf("\nENTER STRING %d:",i+1);
		scanf_s("%s", array_of_pointer[i],30);
	}
	printf("\nTHE STRINGS ENTERED ARE:\n");
	for(int i=0;i< no_of_strings;i++)
		printf("\n%s\n", array_of_pointer[i]);
	_getch();
	return 0;
}