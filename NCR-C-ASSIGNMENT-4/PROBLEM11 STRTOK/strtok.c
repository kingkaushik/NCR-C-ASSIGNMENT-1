#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char* strtok(char[], char[]);
char *str1, *str_replica;
int substr_length = 0;
int str_len = 0, flag = 0;
int main()
{
	char str[30];
	char delimiter[2]="-";
	char *sub_str;
	printf("STRING TOKENIZER\n");
	printf("ENTER THE STRING TO TOKENISE USING -:");
	gets_s(str, 30);
	sub_str = strtok(str, delimiter);
	while (sub_str != NULL)
	{
		printf(" %s\n",sub_str);
		sub_str = strtok(NULL,delimiter);
	}
	_getch();
	return 0;
}
char* strtok(char str[],char delimiter[])
{
	if (flag == 1)
		return NULL;
	if (str != NULL)
	{
		for (; str[str_len]; str_len++);
		str_replica = (char *)calloc(str_len + 1, sizeof(char));
		str1 = (char *)calloc(str_len + 1, sizeof(char));
		for (int i = 0; i < str_len; i++)
		{
			*(str_replica + i) = str[i];
		}
		*(str_replica + str_len) = '\0';
	}
	int i = 0;
	for (; str_replica[substr_length]!='\0'; i++,substr_length++)
	{
		if (str_replica[substr_length] == delimiter[0])
		{
			str1[i] = '\0';
			substr_length++;
			return str1;
		}
		str1[i] = str_replica[substr_length];
	}
	str1[i] = '\0';
	flag = 1;
	return str1;
}