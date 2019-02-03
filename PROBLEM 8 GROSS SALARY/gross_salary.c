#include<stdio.h>
#include<conio.h>
int main()
{
	int base_salary = -1;
	printf("ENTER THE BASE SALARY:");
	scanf_s("%d",&base_salary);
	float gross_salary = -1.0f, hra = -1.0f, dra = -1.0f;
	if (base_salary>=1 && base_salary<=4000)
	{
		hra = 0.1f;
		dra = 0.5f;
	}
	else if (base_salary >= 4001 && base_salary <= 8000)
	{
		hra = 0.2f;
		dra = 0.6f;
	}
	else if (base_salary >= 8001 && base_salary <= 12000)
	{
		hra = 0.25f;
		dra = 0.7f;
	}
	else
	{
		hra = 0.3f;
		dra = 0.8f;
	}
	gross_salary = base_salary*(1 + hra + dra);
	printf("THE GROSS SALARY = %.2f RS/- ONLY",gross_salary);
	_getch();
	return 0;
}