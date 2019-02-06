#include<stdio.h>
#include<conio.h>
int main()
{
	int number = 0,  max = 0, min = 0;
	float average = 0.0f;
	printf("ENTER THE NUMBERS AND TO END THE SEQUENCE ENTER 0 OR NEGATIVE NUMBER:");
	int number_count = 1;
	while (1)
	{
		printf("\nENTER NUMBER %d->", number_count);
		scanf_s("%d",&number);		
		if (number == 0)
			break;
		if (number_count == 1)
			min = number;
		if (max < number)
			max = number;
		if (min > number)
			min = number;
		average += (float)number;
		number_count++;
	}
	average /= (number_count-1);
	if (number_count > 1)
		printf("\n NUMBER OF POSITIVES NUMBER=%d\n MAXIMUM NUMBER=%d\n MINIMUM NUMBER=%d\n AVERAGE VALUE=%.2f", number_count - 1, max, min, average);
	else
		printf("NO NUMBER IS ENTERED TO FIND MAX,MIN,AVG VALUES");
	_getch();
	return 0;
}