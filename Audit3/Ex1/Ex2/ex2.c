#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct 
{
	char word[30];
}gWords;


int main()
{
	setlocale(LC_ALL, "rus");
	gWords *g;
	int n = 0;
	printf("Из скольких слов будем играть?\n");
	scanf_s("%d\n", &n);
	g = (gWords*)malloc(n * sizeof(gWords));
	//system("cls");
	for (int i = 0; i < n; i++)
	{
		printf("Enter %d word: \n", i);
		gets(g[i].word);
	}
	for (int i = 0; i < n; i++)
	{
		printf("\n%s\n", g[i].word);
	}


	system("pause");
	return 0;
}
