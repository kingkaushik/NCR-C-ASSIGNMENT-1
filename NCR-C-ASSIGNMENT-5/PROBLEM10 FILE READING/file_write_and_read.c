#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct country_and_capital
{
	int country_size, capital_length;
	char *country;
	char *capital;
}*s;

int main()
{
	FILE* fptr, *fptr1;
	int no_of_countries = -1;
	fopen_s(&fptr, "country_and_capital.txt", "w");
	if (fptr != NULL)
	{
		printf("\nENTER NUMBER OF COUNTRIES AND THEIR CAPITALS:");
		scanf_s("%d", &no_of_countries);
		s = (struct country_and_capital*)calloc(no_of_countries + 1, sizeof(struct country_and_capital));
		for (int i = 0; i < no_of_countries; i++)
		{
			printf("\nENTER SIZE OF COUNTRY NAME:");
			scanf_s("%d", &(s + i)->country_size);
			int country_size = (s + i)->country_size;
			printf("\nENTER COUNTRY NAME:");
			(s + i)->country = (char*)calloc((s + i)->country_size + 1, sizeof(char));
			char ch[2];
			gets_s(ch, 1);
			gets_s((s + i)->country, country_size + 1);
			printf("\nENTER SIZE OF %s CAPITAL NAME:", (s + i)->country);
			scanf_s("%d", &(s + i)->capital_length);
			int capital_length = (s + i)->capital_length;
			printf("\nENTER %s's CAPITAL NAME:", (s + i)->country);
			(s + i)->capital = (char*)calloc(capital_length + 1, sizeof(char));
			gets_s(ch, 1);
			gets_s((s + i)->capital, capital_length + 1);
			fprintf(fptr, "%s-%s\n", (s + i)->country, (s + i)->capital);
		}
		fclose(fptr);
	}
	else
	{
		printf("ERROR OCCURED");
		exit(1);
	}
	fopen_s(&fptr1, "country_and_capital.txt", "r");
	if (fptr1 != NULL)
	{
		int choice = -1;
		printf("\nENTER THE CHOICE:");
		printf("1) Determine the capital of a specified country");
		printf("\n2) Determine the country whose capital is specified");
		printf("\n3) Terminate the programme");
		printf("\nENTER YOUR CHOICE:");
		scanf_s("%d", &choice);
		int country_size = -1, capital_size = -1;
		char *country1, *capital1;
		int str_length = 0, flag = 0;
		switch (choice)
		{
		case 1:
			printf("ENTER SIZE OF COUNTRY NAME U WANT TO FIND:");
			scanf_s("%d", &country_size);
			printf("ENTER COUNTRY NAME TO FIND IT'S CAPITAL:");
			country1 = (char*)calloc(country_size+1, sizeof(char));
			//country2 = (char*)calloc(country_size+, sizeof(char));
			char c[2];
			gets_s(c, 2);
			gets_s(country1, country_size + 1);
			
			char* str;
			
			while (!feof(fptr1))
			{
				char ch = fgetc(fptr1);				
				if (ch == '\n')
				{
					flag = 0;
					str = (char *)calloc(str_length+2, sizeof(char));
					fseek(fptr1, -str_length-2,SEEK_CUR);
					ch = fgetc(fptr1);					
					int i = 0;
					while (ch != '\n')
					{
						*(str + i) = ch;
						ch = fgetc(fptr1);							
						i++;
					}
					*(str + i) = '\0';					
					char *next_token;
					char *token = strtok_s(str, "-", &next_token);
					if (strcmp(country1, token) == 0)
						printf("\nTHE CAPITAL OF COUNTRY %s IS %s", country1, next_token);
					str_length = -1;	
					free(str);
				}
				str_length++;					
			}			
			fclose(fptr1);
			break;
		case 2:
			printf("ENTER SIZE OF CAPITAL NAME U WANT TO FIND:");
			scanf_s("%d", &capital_size);
			printf("ENTER CAPITAL NAME TO FIND IT'S CAPITAL:");
			capital1 = (char*)calloc(capital_size + 1, sizeof(char));
			//country2 = (char*)calloc(country_size+, sizeof(char));
			char c1[2];
			gets_s(c1, 2);
			gets_s(capital1, capital_size + 1);

			char* str1;

			while (!feof(fptr1))
			{
				char ch = fgetc(fptr1);
				if (ch == '\n')
				{
					flag = 0;
					str1 = (char *)calloc(str_length + 2, sizeof(char));
					fseek(fptr1, -str_length - 2, SEEK_CUR);
					ch = fgetc(fptr1);
					int i = 0;
					while (ch != '\n')
					{
						*(str1 + i) = ch;
						ch = fgetc(fptr1);
						i++;
					}
					*(str1 + i) = '\0';
					char *next_token;
					char *token = strtok_s(str1, "-", &next_token);
					if (strcmp(capital1, next_token) == 0)
						printf("\nTHE COUNTRY OF CAPITAL %s IS %s", capital1, token);
					str_length = -1;
					free(str1);
				}
				str_length++;
			}
			fclose(fptr1);
			break;
		case 3:
			exit(1);
			break;
		default:
			printf("\nINVALID CHOICE");
			break;
		}
	}
	else
	{
		printf("ERROR OCCURED");
	}
	_getch();
	return 0;
}