#include<stdio.h>
#include<conio.h>

struct date
{
	int day;
	int month;
	int year;
};



int main()
{
	long days_between_two_dates = 0;
	struct date date1, date2;
	int month[] = { 31, 28,31,30,31,30,31, 31,30, 31, 30,31 };
	long date1_in_days, date2_in_days, leap_year_days1, leap_year_days2;
	printf("ENTER TWO DATES IN (YY MM DD) FORMAT TO FIND NO OF DAYS BETWEEN THEM\n");
	printf("ENTER YEAR1:");
	scanf_s("%d", &date1.year);
	printf("\nENTER MONTH1:");
	scanf_s("%d", &date1.month);
	printf("\nENTER DAY1:");
	scanf_s("%d", &date1.day);
	printf("\nENTER YEAR2:");
	scanf_s("%d", &date2.year);
	printf("\nENTER MONTH2:");
	scanf_s("%d", &date2.month);
	printf("\nENTER DAY2:");
	scanf_s("%d", &date2.day);
	date1_in_days = (date1.year - 1) * 365;
	for (int i = 0; i < date1.month-1; i++)
	{
		date1_in_days += month[i];
	}
	date1_in_days += date1.day;
	leap_year_days1 = (date1.year) / 4;
	date1_in_days += leap_year_days1;
	date2_in_days = (date2.year - 1) * 365;
	for (int i = 0; i < date2.month - 1; i++)
	{
		date2_in_days += month[i];
	}
	date2_in_days += date2.day;
	leap_year_days2 = (date2.year) / 4;
	date2_in_days += leap_year_days2;
	days_between_two_dates = date1_in_days - date2_in_days;
	days_between_two_dates = days_between_two_dates >= 0 ? days_between_two_dates : -days_between_two_dates;
	printf("NO OF DAYS BETWEEN THE GIVEN TWO DATES IS %ld", days_between_two_dates);
	_getch();
	return 0;
}