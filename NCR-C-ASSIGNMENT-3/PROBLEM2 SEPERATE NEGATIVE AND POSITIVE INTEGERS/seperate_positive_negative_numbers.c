#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int *arr,*arr_replica;
	int n = -1;
	printf("ENTER THE NO OF ARRAY ELEMENTS:");
	scanf_s("%d", &n);
	arr = (int*)calloc(n, sizeof(int));
	arr_replica = (int*)calloc(n, sizeof(int));
	printf("\nENTER ARRAY ELEMENTS");
	for (int i = 0; i < n; i++)
	{
		printf("\nENTER ELEMENT %d:", i + 1);
		scanf_s("%d", (arr + i));
		
	}
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(arr + i) < 0)
		{
			*(arr_replica + j) = *(arr + i);
			j++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (*(arr + i) == 0)
		{
			*(arr_replica + j) = *(arr + i);
			j++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (*(arr + i) > 0)
		{
			*(arr_replica + j) = *(arr + i);
			j++;
		}
	}
	printf("\nNOW THE ELEMENTS ARE->\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ",*(arr_replica+i));
	}
	_getch();
	return 0;
}