#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	float principal = 500000.00f, rate_of_interest = 0.05f;
	int annual_time = 1, semi_annual_time = 2, quarter_annual_time = 4, daily_time = 365,no_of_years=10;
	float simple_interest = principal * no_of_years*rate_of_interest;
	float annual_compound_interest = principal * (pow((1+rate_of_interest/annual_time),annual_time*no_of_years)-1);
	float semi_annual_compound_interest = principal * (pow((1 + rate_of_interest / semi_annual_time), semi_annual_time*no_of_years) - 1);
	float quarter_annual_compound_interest = principal * (pow((1 + rate_of_interest / quarter_annual_time), quarter_annual_time*no_of_years) - 1);
	float daily_compound_interest = principal * (pow((1 + rate_of_interest / daily_time), daily_time*no_of_years) - 1);
	printf("PRINCIPAL=%.2f, RATE OF INTEREST=%.2f, NO OF YEARS=%d\n",principal,rate_of_interest,no_of_years);
	printf("SIMPLE INTEREST=%.2f\n",simple_interest);
	printf("INTEREST COMPOUNDED ANNUALLY =%.2f\n",annual_compound_interest);
	printf("INTEREST COMPOUNDED SEMI-ANNUALLY =%.2f\n", semi_annual_compound_interest);
	printf("INTEREST COMPOUNDED QUARTER-ANNUALLY =%.2f\n", quarter_annual_compound_interest);
	printf("INTEREST COMPOUND DAILY =%.2f\n", daily_compound_interest);
	_getch();
	return 0;
}