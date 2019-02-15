#include<stdio.h>
#include<conio.h>

enum operators { addition = 1 ,subtraction,multiplication };

struct complex
{
	double real_part;
	double imaginary_part;
};

int main()
{
	struct  complex complex_number1, complex_number2;
	int choice = -1;
	double real_part_sum = 0, real_part_difference = 0, real_part_product = 1;
	double imaginary_part_sum = 0, imaginary_part_difference = 0, imaginary_part_product = 1;
	double resultant_product = 0;
	printf("ENTER TWO COMPLEX NUMBERS\n");
	printf("ENTER FIRST COMPLEX NUMBER\n");
	printf("ENTER REAL PART OF FIRST COMPLEX NUMBER:");
	scanf_s("%lf", &complex_number1.real_part);
	printf("\nENTER IMAGINARY PART OF FIRST COMPLEX NUMBER:");
	scanf_s("%lf", &complex_number1.imaginary_part);
	printf("\nENTER REAL PART OF SECOND COMPLEX NUMBER:");
	scanf_s("%lf", &complex_number2.real_part);
	printf("\nENTER IMAGINARY PART OF SECOND COMPLEX NUMBER:");
	scanf_s("%lf", &complex_number2.imaginary_part);
	printf("\nENTER THE OPERATION YOU WANT TO PERFORM");
	printf("\nPRESS 1:ADDITION 2:SUBTRACTION 3:MULTIPLICATION");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case addition:
		 real_part_sum = complex_number1.real_part + complex_number2.real_part;
		 imaginary_part_sum = complex_number1.imaginary_part + complex_number2.imaginary_part;
		 printf("THE RESULTANT SUM IS %.2lf + i%.2lf", real_part_sum, imaginary_part_sum);
		break;
	case subtraction:
		real_part_difference = complex_number1.real_part - complex_number2.real_part;
		imaginary_part_difference = complex_number1.imaginary_part - complex_number2.imaginary_part;
		printf("THE RESULTANT DIFFERENCE IS %.2lf - i%.2lf", real_part_sum, imaginary_part_sum);
		break;
	case multiplication:
		real_part_product = complex_number1.real_part * complex_number2.real_part;
		imaginary_part_product = complex_number1.imaginary_part * complex_number2.imaginary_part;
		resultant_product = real_part_product - imaginary_part_product;
		printf("THE RESULTANT PRODUCT IS %.2lf");
		break;
	default:
		break;
	}
	_getch();
	return 0;
}