#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void strcpy(char *, char *);
int strcmp(char *,char *);
int strlen(char *);
void strcat(char *, char *);
void strrev(char *);
int main()
{
	char *str1, *str1_replica;
	str1 = (char*)calloc(30, sizeof(char));
	str1_replica = (char*)calloc(30, sizeof(char));
	printf("ENTER STR1:");
	scanf_s("%s",str1,30);
	printf("\nCOPY STR1 i.e %s IN STR1_REPLICA", str1);
	strcpy(str1_replica,str1);
	printf("\nSTR1_REPLICA IS %s", str1_replica);
	int str_diff = strcmp(str1_replica, str1);
	if (str_diff == 0)
	{
		printf("\n%s = %s", str1_replica, str1);
	}
	else if (str_diff > 1)
	{
		printf("\n%s > %s", str1_replica, str1);
	}
	else
		printf("\n%s < %s", str1_replica, str1);
	int str1_len = strlen(str1);
	printf("\nLENGTH OF %s IS %d", str1, str1_len);
	printf("\n%s CONCATENATED WITH %s IS", str1,str1_replica);
	strcat(str1, str1_replica);
	printf(" %s\n",str1);
	printf("\nSTRING %s AFTER REVERSING IS",str1_replica);
	strrev(str1_replica);
	printf(" %s\n",str1_replica);
	_getch();
	return 0;
}
void strcpy(char *str1_replica, char *str1)
{
	int i = 0;
	while (*(str1 + i) != '\0')
	{
		*(str1_replica + i) = *(str1 + i);
		i++;
	}
	*(str1_replica + i) = '\0';
}
int strcmp(char *str1_replica, char *str1)
{
	int i = 0, j = 0;
	while (*(str1_replica+i) != *(str1+j))
	{
		i++;
		j++;
	}
	if (i == j)
	{
		return 0;
	}
	else if (*(str1_replica + i) > *(str1))
	{
		return 1;
	}
	return -1;
}
int strlen(char *str1)
{
	int str1_len = 0;
	while (*(str1 + str1_len) != '\0')
	{
		str1_len++;
	}
	return str1_len;
}
void strcat(char *str1, char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	realloc(str1,len2);
	int j = len1;
	for (int i = 0; i < len2; i++,j++)
	{
		*(str1 + j) = *(str2 + i);
	}
	*(str1 + j) = '\0';
}
void strrev(char *str)
{
	int str_length = strlen(str);
	char *str2 = (char *)calloc(str_length, sizeof(char));
	int i = str_length - 1;
	for (int j=0; i >= 0; i-- , j++)
	{
		*(str2 + i) = *(str + j);
	}
	*(str2 + str_length) = '\0';
	strcpy(str, str2);
}