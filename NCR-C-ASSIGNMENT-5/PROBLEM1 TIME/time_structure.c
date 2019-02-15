#include<stdio.h>
#include<conio.h>

struct time
{
	int hours, minutes, seconds;
};

int main()
{
	struct time time_of_day;
	printf("\nENTER HOURS:");
	scanf_s("%d", &time_of_day.hours);
	printf("\nENTER MINUTES:");
	scanf_s("%d", &time_of_day.minutes);
	printf("\nENTER SECONDS:");
	scanf_s("%d", &time_of_day.seconds);
	printf("\nTIME OF THE DAY = %d : %d : %d (HH: MM : SS)", time_of_day.hours, time_of_day.minutes, time_of_day.seconds);
	_getch();
	return 0;
}