#include<stdio.h>
#include<conio.h>
#include<string.h>
# define TEXT_LENGTH 81
int main()
{
	
	char text[TEXT_LENGTH];
	int lettersCounter = 0, digitsCounter = 0, blanksCounter = 0, tabsCounter = 0;
	printf("\nENTER THE TEXT HERE ->");
	//READS THE TEXT MAX UPTO LENGTH OF 80 CHARACTERS AND BREAKS WHEN INPUT ENCOUNTERS A NEW-LINE
	//ALSO CALCULATE COUNT FOR LETTERS,DIGITS,SPACES,TABS
	int character = 0;
	for (; character<TEXT_LENGTH-1; character++)
	{
		scanf_s("%c",&text[character]);
		if (text[character] == '\n')
		{
			text[character] = '\0';
			break;
		}
		if ((text[character] >= 'A' && text[character] <= 'Z') || (text[character] >= 'a' && text[character] <= 'z'))
			lettersCounter++;
		else if (text[character] == ' ')
			blanksCounter++;
		else if (text[character] == '\t')
			tabsCounter++;
		else if (text[character] >= '0' && text[character] <= '9')
			digitsCounter++;
	}
	text[character] = '\0';
	printf("\n THE ENTERED TEXT = %s",text);
	printf("\n THE LETTERS(i.e only alphabets) COUNT=%d",lettersCounter);
	printf("\n THE DIGITS COUNT=%d", digitsCounter);
	printf("\n THE BLANKS COUNT=%d", blanksCounter);
	printf("\n THE TABS COUNT=%d", tabsCounter);
	_getch();
	return 0;
}