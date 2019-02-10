#include<stdio.h>
#include<conio.h>
int main()
{
	float table[2][3] = { {1.1,1.2,1.3},{2.1,2.2,2.3} };
	printf("THE ADDRESS OF 1ST ROW IS %u\n",table);
	printf("THE ADDRESS OF 2ND ROW IS %u\n",(table+1));
	printf("THE ADRESS OF 2ND ROW 1ST COLUMN IS %u\n",*(table+1));
	printf("THE ADRESS OF 2ND ROW 2ND COLUMN IS %u\n", *(table + 1)+1);
	printf("THE VALUE AT 2ND ROW 2ND COLUMN IS %.1f\n", *(*(table + 1)+1));
	printf("THE VALUE AT 1ST ROW 2ND COLUMN IS %.1f\n", *(*(table) + 1));
	printf("THE VALUE AT 2ND ROW 1ST COLUMN IS %.1f\n", *(*(table + 1)));
	printf("THE VALUE AT 1ST ROW 2ND COLUMN PLUS 1 IS %.1f\n", *(*(table)+1)+1);
	_getch();
	return 0;
}