#include<stdio.h>
#include<conio.h>
int main()
{
	int *arr, *sum_arr;
	int n = -1, sum = -1;
	printf("ENTER NUMBER OF ELEMENTS IN THE ARRAY:");
	scanf_s("%d", &n);
	arr = (int *)calloc(n, sizeof(int));
	sum_arr = (int *)calloc(n, sizeof(int));
	int sub_sum = 0, i = 0;
	printf("\nENTER ELEMENTS OF ARRAY");
	for (i = 0; i < n; i++)
	{
		printf("\nENTER ELEMENT %d:",i+1);
		scanf_s("%d", arr+i);
		sub_sum += (*(arr + i));
		*(sum_arr + i) = sub_sum;
	}
	printf("\nENTER THE SUM:");
	scanf_s("%d", &sum);
	int diff = -1, start = -1, end = -1;
	for (i = 0; i < n; i++)
	{
		diff = *(sum_arr + i) - sum;
		if (diff >= 0)
		{
			end = i;
			break;
		}
	}
	int flag = 0;
	for (i = 0; i < n; i++)
	{
		if (diff == 0)
		{
			flag = 1;
			start = i - 1;
			break;
		}
		if (*(sum_arr + i) == diff)
		{
			flag = 1;			
			start = i;
			break;
		}
	}
	if(flag==1)
		printf("\nSUM FOUND BETWEEN %d AND %d", start + 2, end + 1);
	else
	{
		printf("\nSUM NOT FOUND");
	}
	_getch();
	return 0;
}